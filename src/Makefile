CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11
FILES = *.c
TEST = $(wildcard ./test/*.c)
OBJ = $(patsubst %.c, %.o, $(FILES))
OS = $(shell uname -s)

ifeq ($(OS),Linux)
	OPEN_CMD = open
	ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURSE
endif

ifeq ($(OS),Darwin)
	OPEN_CMD = open
	ADD_LIB = -lcheck
endif

all: s21_matrix.a s21_test

s21_test: s21_matrix.a
	$(CC) $(FLAGS) $(TEST) s21_matrix.a -o s21_test $(ADD_LIB)
	./s21_test

s21_matrix.a:
	$(CC) -c $(FLAGS) $(FILES)
	ar rcs s21_matrix.a $(OBJ)
	rm $(OBJ)

gcov_report:
	$(CC) --coverage $(FILES) $(TEST) -o s21_test $(ADD_LIB)
	./s21_test
	gcov $(FILES)
	lcov -t "stest" -o s21_test.info -c -d .
	open ./report/index.html

lcov:
	brew install lcov

brew:
	cd
 	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

clean:
	@rm -f *.gc*
	@rm -f s21_test.info
	@rm -rf report
	@rm -f $(OBJ) *.a
	@rm -rf test.dSYM
	@rm s21_test


style:
	clang-format -style=Google -i $(FILES) *.h test/*.c test/*.h

check:
	clang-format -style=Google -n $(FILES) *.h test/*.c test/*.h

.PHONY: all test s21_matrix.a gcov_report clean format