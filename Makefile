CC=gcc
CFLAGS=-Wall -Werror -Wextra
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS=-lcheck -lm -lpthread
ALL_FLAGS=$(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)
SRCS = s21_create_matrix.c \
		s21_remove_matrix.c \
		s21_eq_matrix.c \
		s21_sum_matrix.c \
		s21_sub_matrix.c \
		s21_mult_number.c \
		s21_mult_matrix.c \
		s21_transpose.c \
		s21_calc_complements.c \
		s21_determinant.c \
		s21_inverse_matrix.c

OBJS = $(SRCS:.c=.o)
NAME = test


all: s21_matrix.a gcov_report test

test: $(OBJS) s21_matrix_test.c
	$(CC) $(CFLAGS) $(CHECK_FLAGS) s21_matrix_test.c $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS) *.o *.gcno *.gcda *.info *.a $(NAME) check_res finish

s21_matrix.a: $(OBJS)
	ar rc s21_matrix.a $(OBJS)
	ranlib s21_matrix.a

gcov_report: s21_matrix_test.c
# checkmk test.check > s21_matrix_test.c
	$(CC) -o $(NAME) $(SRCS) s21_matrix_test.c $(ALL_FLAGS) 
	./$(NAME)
	geninfo *.gcda *.gcno -b . -o check_res 
	genhtml check_res -o finish