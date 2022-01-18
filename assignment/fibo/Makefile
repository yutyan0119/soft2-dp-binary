CC = gcc



CFLAGS = -Wall
LDLIBS = -lm

# wildcard関数で SRCDIR以下のcファイルをリスト
SRCS = $(wildcard *.c)
# SRCSの拡張子を置き換える
OBJS = $(SRCS:%.c=%.o)


TARGET = fibo

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)


.PHONY: tmpclean clean

tmpclean:
	rm -f $(SRCDIR)/*~ *~
clean: tmpclean
	rm -f $(TARGET) $(GENCITY) $(OBJS)
