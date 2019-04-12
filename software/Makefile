CC = g++
CFLAGS = -Wall -g
LIBS = -lwiringPi -lm -lusb-1.0

TARGET = main
TARGET2 = main2
SRCS = drive.cpp colorSensor.cpp pi2Arduino.cpp vision.cpp pickup.cpp game.cpp
DEPS = pins.h

OBJS = $(SRCS:.cpp=.o)
HDRS = $(SRCS:.cpp=.h)

all: $(TARGET)

fake: $(TARGET2)

$(TARGET): $(TARGET).cpp $(OBJS) $(DEPS) $(TARGET).o
	$(CC) -o $(TARGET) $(TARGET).o  $(OBJS) ~/astrohub/pixy2/build/libpixyusb2/libpixy2.a $(LIBS) $(CFLAGS)

$(TARGET2): $(TARGET2).cpp $(OBJS) $(DEPS) $(TARGET2).o
	$(CC) -o $(TARGET2) $(TARGET2).o  $(OBJS) ~/astrohub/pixy2/build/libpixyusb2/libpixy2.a $(LIBS) $(CFLAGS)

$(TARGET).o: $(TARGET).cpp $(DEPS)
	$(CC) -c -o $(TARGET).o $(TARGET).cpp

$(TARGET2).o: $(TARGET2).cpp $(DEPS)
	$(CC) -c -o $(TARGET2).o $(TARGET2).cpp

vision.o: vision.cpp vision.h $(DEPS)
	g++  -g -fpermissive -I /usr/include/libusb-1.0 -I ~/astrohub/pixy2/src/host/libpixyusb2/include -I ~/astrohub/pixy2/src/host/arduino/libraries/Pixy2  -c -o vision.o vision.cpp

%.o: %.cpp %.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

clean:
	rm $(OBJS) main main.o
