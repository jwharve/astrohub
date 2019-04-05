CC = g++
CFLAGS = -Wall -g
LIBS = -lwiringPi -lm

TARGET = main
SRCS = elevator.cpp drive.cpp colorSensor.cpp pi2Arduino.cpp vision.cpp
DEPS = pins.h

OBJS = $(SRCS:.cpp=.o)
HDRS = $(SRCS:.cpp=.h)
EXE = $(SRCS:.cpp=)

all: $(TARGET)

$(TARGET): $(TARGET).cpp $(OBJS) $(DEPS)
	$(CC) -o $(TARGET) $(TARGET).cpp $(OBJS) $(CFLAGS) $(LIBS)

%.o: %.c %.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

clean:
	rm $(OBJS) main
