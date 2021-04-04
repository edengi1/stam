export LD_LIBRARY_PATH=.

all: runall main1_1 main1_2 main1_3

main1_1: main1_1.o hello_ariel.o
	gcc -Wall -g -o main1_1 main1_1.o hello_ariel.o

main1_1.o: main1_1.c hello_ariel.h
	gcc -c -Wall -g main1_1.c 

hello_ariel.o: hello_ariel.c hello_ariel.h
	gcc -c -g -Wall hello_ariel.c 

main1_2: main1_2.o
	gcc -Wall -g -o main1_2 main1_2.o hello_ariel.so

main1_2.o: main1_2.c lib
	gcc -c -Wall -g main1_2.c 

lib: hello_ariel.c hello_ariel.h
	gcc -shared -fPIC hello_ariel.c -L. -o hello_ariel.so

main1_3: main1_3.o lib
	gcc main1_3.c -L. -ldl hello_ariel.so -o main1_3

runall: main1_1 main1_2 main1_3
	./main1_1 && ./main1_2 && ./main1_3
clean:
	rm -f main1_1 main1_2 main1_3 *.o *.so
