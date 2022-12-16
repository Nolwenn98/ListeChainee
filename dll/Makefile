CC ?= gcc
CFLAGS += -Wall --pedantic -Werror -Wno-error=unused-but-set-variable -Wno-error=unused-variable

lib:
	$(CC) $(LDFLAGS) -shared -o liblinked_list.so -fPIC list.c


clean:
	rm -f *.o tests_list list


