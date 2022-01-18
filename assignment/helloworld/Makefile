CC = gcc


CFLAGS = -Wall
LDLIBS = -lm

# wildcard関数で SRCDIR以下のcファイルをリスト
SRCS = $(wildcard *.c)
# SRCSの拡張子を置き換える
OBJS = $(SRCS:%.c=%.o)


TARGET = helloworld
CALC = calc_magicnumber

all: $(TARGET) $(CALC)

$(TARGET): helloworld1.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(CALC): calc_magicnumber.c
	$(CC) -o $@ $^ -lm

.PHONY: tmpclean clean

tmpclean:
	rm -f $(SRCDIR)/*~ *~
clean: tmpclean
	rm -f $(TARGET) $(GENCITY) $(OBJS)
