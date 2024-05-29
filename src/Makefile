CC=g++ 
CFLAGS= -Wall -Wextra -Werror -g -std=c++17 
GCR=
GCC =$(CC) $(CFLAGS)
# CHECKFLAGS=-lgtest
GCOV=--coverage -pthread -fprofile-arcs -ftest-coverage
OS = $(shell uname)
BIN_FILE=CalcCPP

ifeq ($(OS), Darwin)
    # FLAGS += -D MACOS
	OPEN:=open
	QMAKE:=qmake
	CC=clang++
	CFLAGS+=$(shell pkg-config --cflags gtest)
	LIBS+=$(shell pkg-config --libs gtest)
else
	LIBS += -lsubunit -lrt -lm -lpthread
	OPEN:=xdg-open
	QMAKE:=qmake6
endif

all: test clean

dvi:
	open dvi/README.md

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css report *.txt *.dSYM ./build calc_test

install: uninstall
	mkdir -p build
	mkdir $(HOME)/Desktop/Calculator
	cd build && qmake6 ../CalcCPP/CalcCPP.pro && make
	cp -rf build/CalcCPP.app $(HOME)/Desktop/Calculator/CalcCPP.app
	cd $(HOME)/Desktop/Calculator/CalcCPP.app/Contents/MacOS &&./CalcCPP

uninstall:
	rm -rf $(HOME)/Desktop/Calculator/
	rm -rf build

# s21_matrix.a:
# 	$(GCC) -c s21_*.cc -o matrix.o
# 	ar rcs matrix.a matrix.o

test: 
	$(GCC) $(GCOV) -c MVC/model.cpp MVC/controller.cpp MVC/credit_model.cpp
	$(GCC) -c tests.cpp 
	$(GCC) $(GCOV) $(LIBS)  -o calc_test tests.o credit_model.o model.o controller.o -g
	./calc_test
#  make clean

mytest:
	@echo --------------------MYTEST-----------------------
	$(GCC) -std=c++17 -o  calc MVC/model.cpp MVC/controller.cpp MVC/credit_model.cpp test_main.cpp -lm -g
	@./calc
#	@rm calc

cppcheck:
	@echo -------------------CPPCHECK------------------------
	cppcheck --enable=all --suppress=missingIncludeSystem . *.cc

clang:
	@echo -------------------CLANG_FORMAT------------------------
	@ cp ../materials/linters/.clang-format .
	clang-format -n -style=Google *.cpp *.h
	clang-format -i -style=Google *.cpp *.h
	@rm clang-format


leaks: test
ifeq ($(OS), Linux)
	CK_FORK=no valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./calc_test
else
	leaks -atExit --leak-check=full --show-leak-kinds=all  ./calc_test 
endif

gcov_report: test
	lcov -t "calc_test" -o calc_test.info --no-external -c --directory . --capture


#	lcov  -t "calc_test" -o calc_test.info --no-external -c -d  . --gcov-tool "/opt/goinfre/$(USER)/homebrew/opt/llvm/bin/llvm-cov gcov"
	genhtml -o report/ calc_test.info
	open ./report/index.html
	rm -rf calc_test *.o *.a *gcda *gcno *info

	# gcovr $(GCR) --decisions \
	# --html-details $(COV_REPORT)gcov_report.html \
	# --html-theme github.dark-blue
	# rm -rf *.info && rm -rf *.gcov
	# @if command -v xdg-open > /dev/null; then \
    #     xdg-open $(COV_REPORT)gcov_report.html; \
    # elif command -v open > /dev/null; then \
    #     open $(COV_REPORT)gcov_report.html; \
    # else \
    #     echo "Cannot open browser. Please open '$(COV_REPORT)gcov_report.html' manually."; \
    
	
	# @$(LCOV_PATH) --capture --directory . --output-file calc_test.info
	# @geninfo --ignore-errors mismatch . --output-file calc_test.info
	# @genhtml -o report calc_test.info
	# @open report/index.html