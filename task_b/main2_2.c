#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

#define STACK_SIZE 10000

int foo(char *str) {
    printf("Hello from %s\n", str);
    sleep(55);
    exit(1);
}

int handler() {
    sleep(5);
    foo("Child process");
    return 1;
}

int main() {


    printf("----------------- TASK 2 -----------------\n");
    char stack[STACK_SIZE + 1];
    
    int proc1 = clone(handler, stack + STACK_SIZE, CLONE_PARENT, 0);
    int proc2 = clone(handler, stack + STACK_SIZE, CLONE_PARENT, 0);


    printf("pid1: %d\npid2: %d\n", proc1, proc2);



    foo("Parent process");
    sleep(50);
    printf("Task 2 finished!\n");
    

    return 0;
}