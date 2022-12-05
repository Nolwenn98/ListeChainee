CC ?= gcc
CFLAGS += -Wall --pedantic -Werror -Wno-error=unused-but-set-variable -Wno-error=unused-variable

all:
	$(CC) $(LDFLAGS) -o d_ll $(CFLAGS) d_ll_functions.c main.c -lm 

test:
	$(CC) $(LDFLAGS)  -o tests_d_ll $(CFLAGS) test_d_ll.c d_ll_functions.c -lcunit

test_debug:
	$(CC) $(LDFLAGS)  -o debug_tests_d_ll $(CFLAGS) $(DEBUG_FLAGS) test_d_ll.c d_ll_functions.c -lcunit


clean:
	rm -f *.o tests_d_ll d_ll debug_tests_d_ll


