CC:=gcc
SRCS:=$(wildcard *.c)
TARGETS:=$(SRCS:%.c=%)
all:$(TARGETS)
%:%.c
	$(CC) -g $< -o $@

clean:
	rm -rf $(TARGETS)
