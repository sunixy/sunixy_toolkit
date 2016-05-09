#sunixy toolkit list Makefile
CC=gcc

INC=-I./include -I../include/
SRC=./src
file=$(SRC)/physical_value.c
objects=physical_value.o

$(objects):$(file)
	$(CC) $(INC) -c $(file) -o $(objects)


.PHONY:clean test
clean:
	-rm $(objects)

test:
	#$(CC) $(INC) ./src/st_list.c ./test/main.c -o ./test/test_main 
	$(MAKE)	
	$(CC) $(INC) $(objects) ./test/main.c -o ./test/test_main -lm



