GCC=gcc
OBJ_ALL=sort.o prog test
OBJ=sort.o
LIB=-lcunit

all: $(OBJ_ALL)

prog: $(OBJ)
	$(GCC) main.c $(OBJ) -o prog

test: $(OBJ)
	$(GCC) test.c $(OBJ) $(LIB) -o tests

sort.o:
	$(GCC) -c sort.c -o sort.o

clean:
	rm *.o *.xml prog tests
