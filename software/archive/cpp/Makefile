IDIR = include
COMPILER = g++
FLAGS = -g -Wall -Werror -std=c++11 -Weffc++ -Wextra -pedantic -I $(IDIR)

EXECUTABLE = robot.exe
OBJECTS = \
		  main.o \
		  robot.o \
		  navigation.o \
		  collection.o \
		  elevation.o \
		  distribution.o \
		  celebration.o

%.o: %.cpp $(IDIR)/%.h
	$(COMPILER) $(FLAGS) -c $< -o $@

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) $(FLAGS) -o $@ $(OBJECTS)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean: 
	rm -rf $(OBJECTS)
	rm -rf $(EXECUTABLE)

.SUFFIXES:
