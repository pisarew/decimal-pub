CFLAGS := -g -Wall -Wextra -I ./
OS := $(shell uname -s)
LIB_SOURCE_FILES := common.c converters.c arithmetic.c additional.c comparison.c
TESTS_SOURCE_FILES := tests.c $(wildcard tests/*.c)
CC := gcc

ifeq ($(OS), Darwin)
	TEST_FLAGS = -lcheck
else
	TEST_FLAGS = -lcheck -lpthread -pthread -lrt -lsubunit -lm
endif

all: test

test: clean build
	./test

build: s21_decimal.a
	${CC} ${CFLAGS} -o test ${TESTS_SOURCE_FILES} ${TEST_FLAGS} s21_decimal.a

s21_decimal.a: $(LIB_SOURCE_FILES:.c=.o)
	ar rc s21_decimal.a $^
	ranlib s21_decimal.a

clean:
	rm -rf test *.html *.css *.gcno *.gcda *.o *.a

gcov_report: clean tests.c
	gcc $(CFLAGS) --coverage ${LIB_SOURCE_FILES} ${TESTS_SOURCE_FILES} -o test $(TEST_FLAGS)
	./test
	gcovr -r . --html --html-details -o coverage_report.html
	open coverage_report.html

linter:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h
	rm -rf .clang-format

vg: clean build
	 valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test
