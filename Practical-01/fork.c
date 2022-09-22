/*
    Write a C program to demonstrate the use of fork() system call.

    Fork system call is used to create a new process which is called the child process which runs concurrently with the parent process. The parent process is the process which makes the fork() call. Fork() function is defined in header unistd. Fork() system call is Unix/Linux specific system call.
    PID is the Process Identification Number on Linux/Unix OS.
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Name - Vishal Joshi\nSection - A\nStudent id - 20011368\n\n");
    fork();
    printf("Hello World!\n");
    printf("Get PID: %d\n\n", getpid());
    return 0;
}