/*
    C Program to Implement Safety Algorithm- (Banker's Algorithm- Deadlock Avoidance Algorithm)

    This algorithm prints whether the given system state is in SAFE state or UNSAFE state. If safe, then prints the SAFE SEQUENCE.
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct process
{
    int max[10], allocated[10], need[10];
} st;

int n, r;

void input(st process[], int available[])
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter process[%d] info -\n", i);
        printf("Enter Maximum Need : ");
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &process[i].max[j]);
        }

        printf("Enter Allocated Resources for this process : ");
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &process[i].allocated[j]);
            process[i].need[j] = process[i].max[j] - process[i].allocated[j];
        }
    }

    printf("Enter Available Resources : ");
    for (int i = 0; i < r; i++)
    {
        scanf("%d", &available[i]);
    }
}

void showTheInfo(st process[])
{
    printf("\nPID\tMaximum\t\tAllocated\tNeed\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", i);
        for (int j = 0; j < r; j++)
        {
            printf("%d ", process[i].max[j]);
        }

        printf("\t\t");
        for (int j = 0; j < r; j++)
        {
            printf("%d ", process[i].allocated[j]);
        }

        printf("\t\t");
        for (int j = 0; j < r; j++)
        {
            printf("%d ", process[i].need[j]);
        }

        printf("\n");
    }
}

bool applySafetyAlgo(st process[], int available[], int safeSequence[])
{
    bool finish[n];
    int work[r];

    for (int i = 0; i < r; i++)
    {
        work[i] = available[i];
    }

    for (int i = 0; i < n; i++)
    {
        finish[i] = false;
    }

    bool proceed = true;
    int k = 0;

    while (proceed)
    {
        proceed = false;
        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            if (finish[i] == false)
            {
                for (int j = 0; j < r; j++)
                {
                    if (process[i].need[j] <= work[j])
                    {
                        continue;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == false)
                {
                    continue;
                }
                for (int j = 0; j < r; j++)
                {
                    work[j] = work[j] + process[i].allocated[j];
                }
                finish[i] = true;
                safeSequence[k++] = i;
                proceed = true;
            }
        }
    }

    int i;
    for (i = 0; i < n && finish[i] == true; i++)
    {
        continue;
    }

    if (i == n)
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool isSafeState(st process[], int available[], int safeSequence[])
{
    if (applySafetyAlgo(process, available, safeSequence) == true)
    {
        return true;
    }
    return false;
}

int main()
{
    printf("\nName - Vishal Joshi\nSection - A\nStudent id - 20011368\n\n");

    printf("Enter No of Process : ");
    scanf("%d", &n);

    printf("\nEnter No of Resource Instances in system : ");
    scanf("%d", &r);

    int available[r], safeSequence[n];
    st process[n];

    input(process, available);
    printf("\n");

    showTheInfo(process);
    printf("\n");

    if (isSafeState(process, available, safeSequence))
    {
        printf("Safe Sequence is : \n");
        for (int i = 0; i < n; i++)
        {
            printf("Process no - %d\n", safeSequence[i]);
        }
    }

    else
    {
        printf("\nSystem is in UNSAFE State\n");
    }

    return 0;
}
