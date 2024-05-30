CC=g++
CFLAGS= -Wall -Wextra -Werror -g -std=c++17 
GCC =$(CC) $(CFLAGS)
GCOV=--coverage -pthread -fprofile-arcs -ftest-coverage
OS=$(shell uname)
BIN_FILE=CalcCPP

ifeq ($(OS), Darwin)
    # FLAGS += -D MACOS
	OPEN:=open
	QMAKE:=qmake
	CC=clang++
	CFLAGS+=$(shell pkg-config --cflags gtest)
	LIBS+=$(shell pkg-config --libs gtest)
else
	LIBS+= -lsubunit -lgtest -lgmock -lrt -lm -lpthread
	OPEN:=xdg-open
	QMAKE:=qmake6
endif

all: tests clean

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css report *.txt *.dSYM ./build calc_test

install: uninstall
	mkdir -p build
	mkdir $(HOME)/Desktop/Calculator
	cd build && qmake ../CalcCPP/CalcCPP.pro && make
	# cp -rf build/CalcCPP.app $(HOME)/Desktop/Calculator/CalcCPP.app
	cd build/CalcCPP.app/Contents/MacOS &&./CalcCPP

uninstall:
	rm -rf $(HOME)/Desktop/Calculator/
	rm -rf build


tests: 
	$(GCC) $(GCOV) -c MVC/model.cpp MVC/controller.cpp MVC/credit_model.cpp
	$(GCC) -c calc_tests.cpp 
	$(GCC) $(GCOV) -o calc_test calc_tests.o credit_model.o model.o controller.o $(LIBS)  -g
	./calc_test
#-lgtest -lgmock -lrt -lm -lpthread
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


leaks: tests
ifeq ($(OS), Linux)
	CK_FORK=no valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./calc_test
else
	leaks -atExit --leak-check=full --show-leak-kinds=all  ./calc_test 
endif

gcov_report: tests
	lcov -t "calc_test" -o calc_test.info --no-external -c --directory . --capture 
	genhtml -o report/calc_test.html calc_test.info
	open ./report/index.html
	rm -rf calc_test *.o *.a *gcda *gcno *info

dvi:
	open report/README.md

dist:
	cd .. && tar -czf s21_SmartCalc_v2.0.tgz src
