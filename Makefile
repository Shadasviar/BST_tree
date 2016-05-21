
## Created by Anjuta

CC = gcc
CFLAGS = -g -Wall -std=c11
OBJECTS = $(SOURCES:.c=.o)
SOURCES = tree.c binary_tree.c fractions.c
INCFLAGS = 
LDFLAGS = -Wl,-rpath,/usr/local/lib, -lm
LIBS = 

all: $(SOURCES) tree

tree: $(OBJECTS)
	$(CC) -o tree $(OBJECTS) -L $(LDFLAGS) $(LIBS)

.SUFFIXES:
.SUFFIXES:	.c .cc .C .cpp .o

.c.o : $(SOURCES)
	$(CC) -o $@ -c $(CFLAGS) $< $(INCFLAGS)

count:
	wc *.c *.cc *.C *.cpp *.h *.hpp

clean:
	rm -f *.o

.PHONY: all
.PHONY: count
.PHONY: clean
