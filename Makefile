CC=gcc
FLAGS= -Wall -g 
AR=ar
OBJECTS_ISORT= isort.o 
OBJECTS_TXTFIND= txtfind.o
OBJECTS_MAIN_ISORT= isort.c
OBJECTS_MAIN_TXTFIND= txtfind.c

.PHONY= all clean 
all: txtfind isort

txtfind: $(OBJECTS_TXTFIND)
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_TXTFIND)
isort: $(OBJECTS_ISORT)
	$(CC) $(FLAGS) -o isort $(OBJECTS_ISORT)
isort.o: $(OBJECTS_MAIN_ISORT)
	$(CC) $(FLAGS) -c $(OBJECTS_MAIN_ISORT)
txtfind.o: $(OBJECTS_MAIN_TXTFIND)
	$(CC) $(FLAGS) -c $(OBJECTS_MAIN_TXTFIND)

clean:
	rm -f *.a *.o txtfind isort
