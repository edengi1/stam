#define _GNU_SOURCE
#include <dlfcn.h>
#include "hello_ariel.h"

int main() {


    void *lib = dlopen("./hello_ariel.so", RTLD_LAZY);

    if(lib == NULL) {
        printf("File not found!\n");
        return -1;
    }


    void (*fnc)() = (void *)dlsym(lib, "welcome");

    if (fnc == NULL) {
        printf("Function not found!\n");
        return -1;
    }

    fnc("Welcome Tal!");
    // welcome("Itay and Tal");
    return 0;
}