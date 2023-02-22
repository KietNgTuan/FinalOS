#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <linux/kernel.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <spawn.h>

extern char **environ;

// function to execute test1.o
void *test1(void *arg){

    // char *args[] = {"./test1",NULL};
    pid_t pid;
    char *text = strdup("My string literal!");
    char *argv[] = {NULL};
    int status;
    status = posix_spawn(&pid, "./test1", NULL, NULL, argv, environ);
    if (status == 0)
    {
        printf("Child pid 1: %i\n", pid);
    }
    // execv(args[0],args);
    return NULL;
}

// function to execute test2.0
void *test2(void *arg){
    // char *args[] = {"./test1",NULL};
    pid_t pid;
    char *text = strdup("My string literal!");
    char *argv[] = {NULL};
    int status;
    status = posix_spawn(&pid, "./test2", NULL, NULL, argv, environ);
    if (status == 0)
    {
        printf("Child pid 2: %i\n", pid);
    }
    // execv(args[0],args);
    return NULL;
}

// function to execute test3.o
void *test3(void *arg){
    // char *args[] = {"./test1",NULL};
    pid_t pid;
    char *text = strdup("My string literal!");
    char *argv[] = {NULL};
    int status;
    status = posix_spawn(&pid, "./test3", NULL, NULL, argv, environ);
    if (status == 0)
    {
        printf("Child pid 3: %i\n", pid);
    }
    // execv(args[0],args);
    return NULL;
}

int main(){
    int x;

    x = fork();
    if (x == 0)
    {
        test1(NULL);
    }
    else
    {
        x = fork();
        if (x == 0)
        {
            test2(NULL);
        }
        else
        {
            x = fork();
            if (x == 0)
            {
                test3(NULL);
            }
        }
    }

    // for (int i=0;i < 10;i++){
    //     x = fork();
    //     if (x == 0){
    //         if ((i % 3) == 0){
    //             test1(NULL);
    //         }
    //         else if ((i % 3) == 1){
    //             test2(NULL);
    //         }
    //         else if ((i % 3) == 2){
    //             test3(NULL);
    //         }
    //     }

    // }

    return 0;
}
