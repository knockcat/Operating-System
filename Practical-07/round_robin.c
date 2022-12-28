/*
    Write a C program to demonstrate Round Robin Scheduling.

    Round Robin CPU Algorithm generally focuses on Time Sharing technique. The period of time for which a process or job is allowed to run in a pre-emptive method is called time quantum. Each process or job present in the ready queue is assigned the CPU for that time quantum, if the execution of the process is completed during that time then the process will end else the process will go back to the waiting table and wait for its next turn to complete the execution.
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct process
{
    int pid, at, bt, ct, tat, wt, rt, st, remaining, visited;
} st;

int comp(const void *a, const void *b)
{
    st *p1 = (st *)a;
    st *p2 = (st *)b;
    return p1->at > p2->at;
}

int max(int a, int b)
{
    if (a <= b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

void averageTime(st *arr, int n, float total_it)
{
    float total_wt = 0, total_tat = 0, total_rt = 0;

    printf("\nPid\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        total_wt += arr[i].wt;
        total_tat += arr[i].tat;
        total_rt += arr[i].rt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt, arr[i].rt);
    }

    printf("\nAverage Waiting time %f\n", total_wt / (float)n);
    printf("Average Turn Around time %f\n", total_tat / (float)n);
    printf("Average Response time %f\n", total_rt / (float)n);
    printf("CPU utilization %f\n", ((arr[n - 1].ct - total_it) / (float)arr[n - 1].ct) * 100);
    printf("Throughput %f\n", (float)n / (arr[n - 1].ct - arr[0].at));
}

int main()
{
    int n, completed = 0, curr_time = 0, first_process = 0, qn, front = -1, rear = -1;
    int queue[100];
    float total_it = 0;

    printf("\nName - Vishal Joshi\nSection - A\nStudent id - 20011368\n\n");

    printf("Enter the Number of elements : ");
    scanf("%d", &n);

    st arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("For process %d Enter Arrival time and Burst time respectively : ", i + 1);
        arr[i].pid = i + 1;
        scanf("%d%d", &arr[i].at, &arr[i].bt);
        arr[i].remaining = arr[i].bt;
        arr[i].visited = 0;
    }

    printf("Enter time quantam:- ");
    scanf("%d", &qn);
    qsort(arr, n, sizeof(st), comp);
    front = rear = 0;
    queue[rear] = 0;
    arr[0].visited = 1;

    while (completed != n)
    {
        int index = queue[front];
        front++;

        if (arr[index].bt == arr[index].remaining)
        {
            arr[index].st = max(curr_time, arr[index].at);
            curr_time = arr[index].st;
            if (first_process == 1)
            {
                total_it += 0;
            }
            else
            {
                total_it += arr[index].st - curr_time;
            }
        }

        if (arr[index].remaining - qn > 0)
        {
            arr[index].remaining -= qn;
            curr_time += qn;
        }

        else
        {
            curr_time += arr[index].remaining;
            completed++;
            arr[index].ct = curr_time;
            arr[index].tat = arr[index].ct - arr[index].at;
            arr[index].wt = arr[index].tat - arr[index].bt;
            arr[index].rt = arr[index].st - arr[index].at;
            arr[index].remaining = 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i].at <= curr_time && arr[i].visited != 1)
            {
                rear++;
                queue[rear] = i;
                arr[i].visited = 1;
            }
        }

        if (arr[index].remaining != 0)
        {
            rear++;
            queue[rear] = index;
        }
    }

    averageTime(arr, n, total_it);

    return 0;
}