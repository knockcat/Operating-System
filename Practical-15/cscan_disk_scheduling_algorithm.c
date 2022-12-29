/*
    Write a C program to implement C-SCAN disk scheduling algorithm in Operating Systems.

    In C-SCAN algorithm, the arm of the disk moves in a particular direction servicing requests until it reaches the last cylinder, then it jumps to the last cylinder of the opposite direction without servicing any request then it turns back and start moving in that direction servicing the remaining requests.
*/

#include <stdlib.h>
#include <stdio.h>
#define LOW 0
#define HIGH 199

int main()
{
    printf("\nName - Vishal Joshi\nSection - A\nStudent id - 20011368\n\n");

    int n, seektime = 0, head, i, j, diff, max, temp, temp1 = 0, temp2 = 0;

    printf("Enter the number of sequence : ");
    scanf("%d", &n);

    int seq[n], queue1[n], queue2[n];

    printf("Enter the position of head: ");
    scanf("%d", &head);

    printf("Enter the Sequence : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (temp >= head)
        {
            queue1[temp1] = temp;
            temp1++;
        }
        else
        {
            queue2[temp2] = temp;
            temp2++;
        }
    }

    // sort both arrays
    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (queue1[i] > queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }

    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (queue2[i] > queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }

    printf("The C-SCAN Sequence is : ");
    // calculate closest edge
    if (abs(head - LOW) >= abs(head - HIGH))
    {
        for (i = 1, j = 0; j < temp1; i++, j++)
        {
            seq[i] = queue1[j];
        }
        seq[i] = HIGH;
        seq[i + 1] = 0;
        for (i = temp1 + 3, j = 0; j < temp2; i++, j++)
        {
            seq[i] = queue2[j];
        }
    }
    else
    {
        for (i = 1, j = temp2 - 1; j >= 0; i++, j--)
        {
            seq[i] = queue2[j];
        }
        seq[i] = LOW;
        seq[i + 1] = HIGH;
        for (i = temp2 + 3, j = temp1 - 1; j >= 0; i++, j--)
        {
            seq[i] = queue1[j];
        }
    }

    seq[0] = head;

    for (j = 0; j <= n + 1; j++)
    {
        diff = abs(seq[j + 1] - seq[j]);
        seektime += diff;
        printf("%d ", seq[j]);
    }

    printf("\nTotal Seek Time is : %d\n", seektime);

    return 0;
}
