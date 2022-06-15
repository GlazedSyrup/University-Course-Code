CC = g++
CFLAGS = -c

HEADER = shape.h circle.h square.h shapemanager.h rightangletriangle.h
CPP = main.cpp rightangletriangle.cpp

PROG = shapify

OBJ = $(CPP:.cpp=.o)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -o $@ $<

$(PROG): $(OBJ) $(HEADER)
	$(CC) -o $@ $(OBJ) -l sm -L .

.PHONY: clean

clean:
	rm -i $(OBJ) $(PROG)