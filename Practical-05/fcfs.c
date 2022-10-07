// First Come First Serve

#include<stdio.h>
#include<stdlib.h>

typedef struct process
{
    int at, bt, st, ct, tat, wt, rt, pid;
} st;

int comp(const void *a, const void *b)
{
    st *p1 = (st *)a;
    st *p2 = (st *)b;
    return p1->at > p2->at;
}

int comp1(const void *a, const void *b)
{
    st *p1 = (st *)a;
    st *p2 = (st *)b;
    return p1->pid > p2->pid;
}

void averageTime(st *arr, int n)
{
    qsort(arr, n, sizeof(st), comp1);
    float total_wt = 0, total_tat = 0, total_rt = 0, total_it = 0;

    printf("\nPid\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    
    for (int i = 0; i < n; i++)
    {
        total_wt += arr[i].wt;
        total_tat += arr[i].tat;
        total_rt += arr[i].rt;
        total_it += (i == 0) ? arr[i].at : (arr[i].st - arr[i - 1].ct);
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
    printf("\nName - Vishal Joshi\nSection - A\nStudent id - 20011368\n\n");
    int n;

    printf("Enter the Number of elements : ");
    scanf("%d", &n);

    st arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("For process %d Enter Arrival time and Burst time respectively : ", i + 1);
        arr[i].pid = i + 1;
        scanf("%d%d", &arr[i].at, &arr[i].bt);
    }

    qsort(arr, n, sizeof(st), comp);

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            arr[0].ct = arr[0].at + arr[0].bt; // completion time
            arr[0].st = arr[0].at;             // start time
        }
        arr[i].st = (arr[i - 1].ct >= arr[i].at) ? arr[i - 1].ct : arr[i].at; // start time
        if (arr[i].at >= arr[i - 1].ct)
        {
            arr[i].ct = arr[i].at + arr[i].bt; // completion time
        }
        else
        {
            arr[i].ct = arr[i - 1].ct + arr[i].bt; // completion time
        }
        arr[i].rt = arr[i].st - arr[i].at;  // response time
        arr[i].tat = arr[i].ct - arr[i].at; // turn around time
        arr[i].wt = arr[i].tat - arr[i].bt; // waiting time
    }
    
    averageTime(arr, n);
}