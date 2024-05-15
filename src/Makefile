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

build: clean
	@mkdir -p ./build
	$(QMAKE) CalcCPP/CalcCPP.pro -o ./build/$(BIN_FILE)_makefile
	cd ./build && make -f $(BIN_FILE)_makefile
	rm -rf ./build/moc_* ./build/*.o ./build/*.h ./build/$(BIN_FILE)_makefile ./build/.qmake.stash

install: build
ifeq ($(OS), Darwin)
	open ./build/$(BIN_FILE).app/
else 
	./build/$(BIN_FILE)
endif

uninstall:
ifeq ($(OS), Darwin)
	@rm -rf ./build/$(BIN_FILE).app ./build/$(BIN_FILE).tar.gz
else
	@rm -rf ./build/$(BIN_FILE) ./build/$(BIN_FILE).tar.gz
endif

dist: build
ifeq ($(OS), Darwin)
	cd ./build && tar -czvf $(BIN_FILE).tar.gz $(BIN_FILE).app
else
	cd ./build && tar -czvf $(BIN_FILE).tar.gz $(BIN_FILE)
endif

# install:
# 	mkdir build
# 	mkdir $(HOME)/Desktop/Calculator
# 	cd build && cmake ../Calculator/CMakeLists.txt && make
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




