CC:=gcc
SRCS:=$(wildcard *.c)
TARGETS:=$(SRCS:%.c=%)
all:$(TARGETS)
%:%.c
	$(CC) -g $< -o $@ -lpthread

clean:
	rm -rf $(TARGETS)
