CC = gcc
FLAGS=-Wall

all: main1 main2
	
main1: txtF.o 
	$(CC) $(FLAGS) txtF.o -o txtfind
	
txtF.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c -o txtF.o
	
main2: sortArr.o
	$(CC) $(FLAGS) sortArr.o -o isort

sortArr.o: isort.c
	$(CC) $(FLAGS) -c isort.c -o sortArr.o
	
.PHONY: clean all 


clean:
	rm -f main *.o mainP1 mainP2
	
