/*
    Write a C program to demonstrate Zombie Process.

    Zombie Process is a process whose execution is finished but it still has an entry in the process table.
    In this, the parent process is put to sleep for a long time while the child process is terminated using exit(0). When a child process is terminated using exit(0) then the parent process still reads the status of the child process.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Name - Vishal Joshi\nSection - A\nStudent id - 20011368\n\n");

    int pid = fork();

    if (pid > 0)
    {
        sleep(10);
        printf("\nThis is Parent Proces \n");
        printf("PID : %d\n", getpid());
    }
    
    else
    {
        printf("\nThis is Child Process \n");
        printf("PID : %d\n", getpid());
        printf("\nParent PID : %d\n", getppid());
        exit(0);
    }

    return 0;
}