#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int count = 0;
    clock_t start, end;

    while (1)
    {
        start = clock();
        for (int i = 0; i < 50000; i++)
        {
            count++;
        }
        end = clock();

        printf("Process 1(start: %lf, end: %lf\n)", (double)start / CLOCKS_PER_SEC, (double)end / CLOCKS_PER_SEC);
        usleep(1000);
    }
}
