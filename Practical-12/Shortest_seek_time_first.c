/*
    Write a C program to implement SSTF disk scheduling algorithm in Operating Systems.

    Shortest seek time first (SSTF) algorithm selects the disk I/O request which requires the least disk arm movement from its current position regardless of the direction. It reduces the total seek time as compared to FCFS. It allows the head to move to the closest track in the service queue.
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
    printf("\nName - Vishal Joshi\nSection - A\nStudent id - 20011368\n\n");
    int n, seektime = 0, completed = 0, diff = 0, head, pos = 0;

    printf("Enter the number of sequence : ");
    scanf("%d", &n);

    int seq[n], ans[n], visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        ans[i] = 0;
    }

    printf("Enter the Sequence : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &seq[i]);
    }

    printf("Enter the position of head: ");
    scanf("%d", &head);

    while (completed != n)
    {
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] != 1)
            {
                diff = abs(seq[i] - head);
                if (diff < min)
                {
                    min = diff;
                    pos = i;
                }
            }
        }
        seektime = seektime + min;
        ans[completed++] = seq[pos];
        visited[pos] = 1;
        head = seq[pos];
    }

    printf("The SSTF Sequence is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }

    printf("\nTotal Seek Time is : %d\n", seektime);

    return 0;
}