out:=main
SRCS:=$(wildcard *.c) #拿到当前目录下所有的.c
OBJS:=$(patsubst %.c,%.o,$(SRCS)) #预定义变量
CC:=gcc
CFLAGS:=-g -D DEBUG
$(out):$(OBJS)
	gcc $^ -o $@

#.PHONY:clean rebuild
rebuild:clean $(out)
clean:
	rm -rf $(OBJS) $(out)
