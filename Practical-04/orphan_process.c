/*
    Write a C program to demonstrate Orphan Process.

    Orphan Process is a process in which the Parent process terminates before the child process. The child's process is put to sleep for a long time using the sleep function. This will put the child process to sleep and the parent process is terminated making the child process orphan.
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
        exit(0);
    }
    return 0;
}