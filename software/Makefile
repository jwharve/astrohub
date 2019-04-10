CC = g++
CFLAGS = -Wall -g
LIBS = -lwiringPi -lm

TARGET = main
SRCS = drive.cpp colorSensor.cpp pi2Arduino.cpp vision.cpp game.cpp
DEPS = pins.h

OBJS = $(SRCS:.cpp=.o)
HDRS = $(SRCS:.cpp=.h)
EXE = $(SRCS:.cpp=)

all: $(TARGET)

$(TARGET): $(TARGET).cpp $(OBJS) $(DEPS)
	$(CC) -o $(TARGET) $(TARGET).cpp $(OBJS) $(CFLAGS) $(LIBS)

vision.o: vision.c vision.h $(DEPS)
	$(CC) -c -I /usr/include/libusb-1.0 -I ~/astrohub/pixy2/src/host/libpixyusb2/include -I ~/astrohub/pixy2/src/host/arduino/libraries/Pixy2 -o vision.o vision.cpp ~/astrohub/pixy2/build/libpixyusb2/libpixy2.a -lusb-1.0
	
%.o: %.c %.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

clean:
	rm $(OBJS) main
