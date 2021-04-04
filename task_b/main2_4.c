#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


int main() {

    printf("Main PID is %d\n", getpid());

    char *args[] = {NULL};


    pid_t pid = fork();

    if (pid == 0) {
        printf("\nTask: 1 , PID = %d\n", getpid());
        execv("./main2_1", args);
        // exit(1);
    } else {

        pid = fork();

        if(pid == 0) {
            printf("\nTask: 3 , PID = %d\n", getpid());
            execv("./main2_3", args);
            // exit(1);

        } else {
            pid = fork();

            if(pid == 0) {
                printf("\nTask: 2 , PID = %d\n", getpid());
                execv("./main2_2", args);
                // exit(1);
                
            }
        }
    }

    

    printf("Wait for processes: ...\n");

    waitpid(pid, 0, WUNTRACED);

    
    return 0;
}
