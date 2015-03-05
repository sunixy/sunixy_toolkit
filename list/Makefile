#sunixy toolkit list Makefile
CC=gcc

INC=-I./include
SRC=./src
file=$(SRC)/st_list.c
objects=st_list.o

$(objects):$(file)
	$(CC) $(INC) -c $(file) -o $(objects)


.PHONY:clean test
clean:
	-rm $(objects)

test:
	#$(CC) $(INC) ./src/st_list.c ./test/main.c -o ./test/test_main 
	$(MAKE)	
	$(CC) $(INC) $(objects) ./test/main.c -o ./test/test_main 



