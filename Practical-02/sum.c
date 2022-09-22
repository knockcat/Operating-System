/*
    Write a C program in which parent process computes the sum of even Numbers and child process computes the sum of odd number stored in an array using a fork().
    First the child process should print its answer i.e sum of odd number then the parent process should print its answer i.e the sum of even number.

    PID is the Process Identification Number on Linux/Unix OS. In the child process, it returns 0
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Name - Vishal Joshi\nSection - A\nStudent id - 20011368\n\n");

    int ev_sum = 0, od_sum = 0, n;

    printf("Enter the size of the array : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers : \n", n);

    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    int pid = fork();

    if (pid == 0)
    {
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] & 1)
                od_sum += arr[i];
        }

        printf("Sum of Odd Numbers = %d\n", od_sum);
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] % 2 == 0)
                ev_sum += arr[i];
        }
        printf("\nSum of Even Numbers = %d\n", ev_sum);
    }
    return 0;
}