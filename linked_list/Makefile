CC ?= gcc
CFLAGS += -Wall --pedantic -Werror -Wno-error=unused-but-set-variable -Wno-error=unused-variable

all:
	$(CC) $(LDFLAGS) -o list $(CFLAGS) list_functions.c main.c -lm 

test:
	$(CC) $(LDFLAGS)  -o tests_list $(CFLAGS) test_list.c list_functions.c -lcunit

test_debug:
	$(CC) $(LDFLAGS)  -o debug_tests_list $(CFLAGS) $(DEBUG_FLAGS) test_list.c list_functions.c -lcunit


clean:
	rm -f *.o tests_list list


