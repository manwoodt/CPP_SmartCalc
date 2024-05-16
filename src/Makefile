CC=g++ -std=c++17 
GCC =$(CC) -Wall -Wextra -Werror -g
CHECKFLAGS=-lgtest
GCOV=--coverage -pthread -fprofile-arcs -ftest-coverage
OS = $(shell uname)
BIN_FILE=CalcCPP

ifeq ($(OS), Darwin)
	# FLAGS += -D MACOS
	OPEN:=open
	QMAKE:=qmake
else
	LIBS += -lsubunit -lrt -lm -lpthread
	OPEN:=xdg-open
	QMAKE:=qmake6
endif

all: test clean

dvi:
	open ../README.md

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css report *.txt *.dSYM  ./build

install:
	mkdir -p build
	mkdir $(HOME)/Desktop/Calculator
	cd build && qmake ../CalcCPP/CalcCPP.pro  && make
	cp -rf build/CalcCPP.app $(HOME)/Desktop/Calculator/CalcCPP.app
    cd $(HOME)/Desktop/Calculator/CalcCPP.app/Contents/MacOS && ./CalcCPP

uninstall:
	rm -rf $(HOME)/Desktop/Calculator/
	rm -rf build


# dist: build
# ifeq ($(OS), Darwin)
# 	cd ./build && tar -czvf $(BIN_FILE).tar.gz $(BIN_FILE).app
# else
# 	cd ./build && tar -czvf $(BIN_FILE).tar.gz $(BIN_FILE)
# endif

# install:
# 	mkdir build
# 	mkdir $(HOME)/Desktop/Calculator
# 	cd build && qmake ../CalcCPP/CalcCPP.pro  && make
# 	cp -rf build/calculator.app $(HOME)/Desktop/Calculator/Calculator.app

# install:
# 	mkdir -p $(HOME)/Desktop/Calculator/build
# 	cd $(HOME)/Desktop/Calculator/build && qmake../CalcCPP/CalcCPP.pro  && make
# 	cp -rf build/calculator.app $(HOME)/Desktop/Calculator/Calculator.app

# uninstall:
# 	rm -rf $(HOME)/Desktop/Calculator/
# 	rm -rf build


# s21_matrix.a:
# 	$(GCC) -c s21_*.cc -o matrix.o
# 	ar rcs matrix.a matrix.o

test: 
	$(GCC) $(GCOV) -c model.cpp
	$(GCC) -c tests.cpp $(CHECKFLAGS)
	$(GCC) $(GCOV) -o calc_test tests.o model.o $(CHECKFLAGS) -g
	./calc_test
#  make clean

#main.cpp 
mytest:
	@echo --------------------MYTEST-----------------------
	$(GCC) -std=c++17 -o  calc MVC/model.cpp main.cpp -lm -g
	@./calc
#	@rm calc

cppcheck:
	@echo -------------------CPPCHECK------------------------
	cppcheck --enable=all --suppress=missingIncludeSystem . *.cc

clang:
	@echo -------------------CLANG_FORMAT------------------------
	@ cp ../../materials/linters/.clang-format .
	#clang-format -n -style=Google *.cc *.h
	clang-format -i -style=Google *.cc *.h
	@rm clang-format


leaks: test
ifeq ($(OS), Linux)
	CK_FORK=no valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./calc_test
else
	leaks -atExit --leak-check=full --show-leak-kinds=all  ./calc_test 
endif

gcov_report: test
	lcov  -t "test" -o test.info --no-external -c -d  .
	genhtml -o report/ test.info
	open ./report/index.html
	rm -rf test *.o *.a *gcda *gcno *info




