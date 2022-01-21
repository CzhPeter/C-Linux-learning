CC:=gcc
SRCS:=$(wildcard *.c)
TARGETS:=$(SRCS:%.c=%)
all:$(TARGETS)
%:%.c
	$(CC) $< -o $@

clean:
	rm -rf $(TARGETS)
