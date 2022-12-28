/*
    Write a C program to implement LRU page replacement in Operating Systems.

    LRU stands for Least Recently Used. As the name suggests, this algorithm is based on the strategy that whenever a page fault occurs, the least recently used page will be replaced with a new page. So, the page not utilized for the longest time in the memory (compared to all other pages) gets replaced. This strategy is known as LRU paging.
*/

#include <stdio.h>

void lru(int p[50], int f, int n)
{
    int q[f], c = 0, c1, d, i, j, k = 0, r, t, b[f], c2[f];
    q[k] = p[k];
    printf("\nSymbol : %d  in Frame : ", q[k]);
    printf("%d ", q[k]);
    for (int i = 1; i < f; i++)
    {
        q[i] = -1;
        printf("%d ", q[i]);
    }
    c++;
    k++;
    for (i = 1; i < n; i++)
    {
        c1 = 0;
        for (j = 0; j < f; j++)
        {
            if (p[i] != q[j])
            {
                c1++;
            }
        }
        if (c1 == f)
        {
            printf("\nSymbol : %d  in Frame : ", p[i]);
            c++;
            if (k < f)
            {
                q[k] = p[i];
                k++;
                for (j = 0; j < f; j++)
                {
                    printf("%d ", q[j]);
                }
            }
            else
            {
                for (r = 0; r < f; r++)
                {
                    c2[r] = 0;
                    for (j = i - 1; j < n; j--)
                    {
                        if (q[r] != p[j])
                        {
                            c2[r]++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                for (r = 0; r < f; r++)
                {
                    b[r] = c2[r];
                }
                for (r = 0; r < f; r++)
                {
                    for (j = r; j < f; j++)
                    {
                        if (b[r] < b[j])
                        {
                            t = b[r];
                            b[r] = b[j];
                            b[j] = t;
                        }
                    }
                }
                for (r = 0; r < f; r++)
                {
                    if (c2[r] == b[0])
                    {
                        q[r] = p[i];
                    }
                    printf("%d ", q[r]);
                }
            }
        }
        else
        {
            printf("\nSymbol : %d  in Frame : ", p[i]);
            for (int i = 0; i < f; i++)
            {
                printf("%d ", q[i]);
            }
        }
    }
    printf("\nPage hits: %d", n - c);
    printf("\nPage misses: %d\n", c);
}

int main()
{
    int n, no_frames;
    printf("\nName - Vishal Joshi\nSection - A\nStudent id - 20011368\n\n");

    printf("Enter the number of symbols you want to enter : ");
    scanf("%d", &n);

    int page[n];

    printf("Enter %d symbols : ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter the number of frames : ");
    scanf("%d", &no_frames);

    lru(page, no_frames, n);

    return 0;
}