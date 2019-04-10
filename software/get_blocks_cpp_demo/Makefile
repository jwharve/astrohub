CXX=g++
CPPFLAGS=-g -fpermissive -I /usr/include/libusb-1.0 -I ~/astrohub/pixy2/src/host/libpixyusb2/include -I ~/astrohub/pixy2/src/host/arduino/libraries/Pixy2
LDLIBS=~/astrohub/pixy2/build/libpixyusb2/libpixy2.a -lusb-1.0

SRCS=get_blocks_cpp_demo.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: get_blocks

clean:
	rm -f *.o get_blocks_cpp_demo

get_blocks: $(OBJS)
	$(CXX) $(LDFLAGS) -o get_blocks_cpp_demo $(OBJS) $(LDLIBS)
