
## Created by Anjuta

CC = gcc
CFLAGS = -g -Wall -std=c11
OBJECTS = Tree.o binary_tree.o
INCFLAGS = 
LDFLAGS = -Wl,-rpath,/usr/local/lib, -lm
LIBS = 

all: Tree

Tree: $(OBJECTS)
	$(CC) -o Tree $(OBJECTS) -L $(LDFLAGS) $(LIBS)

.SUFFIXES:
.SUFFIXES:	.c .cc .C .cpp .o

.c.o :
	$(CC) -o $@ -c $(CFLAGS) $< $(INCFLAGS)

count:
	wc *.c *.cc *.C *.cpp *.h *.hpp

clean:
	rm -f *.o

.PHONY: all
.PHONY: count
.PHONY: clean
