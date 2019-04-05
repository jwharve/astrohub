CC = gcc
CFLAGS = -Wall -g
LIBS = -lwiringPi

TARGET = main
SRCS = elevator.cpp drive.cpp Sensor.cpp
DEPS = pins.h

OBJS = $(SRCS:.cpp=.o)
HDRS = $(SRCS:.cpp=.h)
EXE = $(SRCS:.cpp=)

all: $(TARGET)

$(TARGET): $(TARGET).c $(OBJS) $(DEPS)
	$(CC) -o $(TARGET) $(TARGET).cpp $(OBJS) $(CFLAGS) $(LIBS)

%.o: %.c %.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

clean:
	rm $(OBJS) main $()
