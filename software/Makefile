CC = gcc
CFLAGS = -Wall
LIBS = -lwiringPi

TARGET = main
SRCS = elevator.c drive.c
DEPS = file.h

OBJS = $(SRCS:.c=.o)
HDRS = $(SRCS:.c=.h)
EXE = $(SRCS:.c=)

all: $(TARGET)

$(TARGET): $(TARGET).c $(OBJS) $(DEPS)
	$(CC) -o $(TARGET) $(TARGET).c $(OBJS) $(CFLAGS) $(LIBS)

%.o: %.c %.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

clean:
	rm $(OBJS) main $()
