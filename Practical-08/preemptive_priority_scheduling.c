/*
    Write a C program to demonstrate Preemptive Priority Scheduling.

    Preemptive Priority Scheduling algorithm is a pre-emptive method of CPU scheduling algorithm that works based on the priority of a process.
    In this algorithm, the scheduler schedules the tasks to work as per the priority, which means that a higher priority process should be executed first.
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct process
{
    int pid, at, bt, ct, tat, wt, rt, st, priority, is_completed, bt_remaining;
} st;

int comp(const void *a, const void *b)
{
    st *p1 = (st *)a;
    st *p2 = (st *)b;
    return p1->at > p2->at;
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
    int n, current_time = 0, completed = 0, prev = 0;
    float total_it = 0;

    printf("\nName - Vishal Joshi\nSection - A\nStudent id - 20011368\n\n");

    printf("Enter the Number of elements : ");
    scanf("%d", &n);

    st arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("For process %d Enter Arrival time and Burst time and priority respectively : ", i + 1);
        arr[i].pid = i + 1;
        scanf("%d%d%d", &arr[i].at, &arr[i].bt, &arr[i].priority);
        arr[i].bt_remaining = arr[i].bt;
        arr[i].is_completed = 0;
    }

    qsort(arr, n, sizeof(st), comp);

    while (completed != n)
    {
        int idx = -1, mx = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].at <= current_time && arr[i].is_completed == 0)
            {
                if (arr[i].priority > mx)
                {
                    mx = arr[i].priority;
                    idx = i;
                }
                if (arr[i].priority == mx)
                {
                    if (arr[i].at < arr[idx].at)
                    {
                        mx = arr[i].priority;
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1)
        {
            if (arr[idx].bt_remaining == arr[idx].bt)
            {
                arr[idx].st = current_time;
                total_it += arr[idx].st - prev;
            }
            arr[idx].bt_remaining -= 1;
            current_time++;
            prev = current_time;

            if (arr[idx].bt_remaining == 0)
            {
                arr[idx].ct = current_time;
                arr[idx].tat = arr[idx].ct - arr[idx].at;
                arr[idx].wt = arr[idx].tat - arr[idx].bt;
                arr[idx].rt = arr[idx].st - arr[idx].at;
                arr[idx].is_completed = 1;
                completed++;
            }
        }
        else
        {
            current_time++;
        }
    }

    averageTime(arr, n, total_it);

    return 0;
}
