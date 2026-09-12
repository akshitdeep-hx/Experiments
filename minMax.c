/*
Min Max recursion problem to sort numbers using DAC approachSS
*/

#include<stdio.h>
#include<stdlib.h>

int DAC(int a[], int low, int high, int* min, int* max)
{
    int mid, min1, max1, min2, max2;

    if(low == high)
    {
        *min = *max = a[low];
        return; 
    }

    if(high == low + 1)
    {
        if(a[low] < a[high])
        {
            *min = a[low];
            *max = a[high];
        }

        else
        {
            *min = a[high];
            *max = a[low];
        }
        return;
    }

    mid = (low + high) / 2;

    DAC(a, low, mid, &min1, &max1);
    
    
}

int main()
{
    int i, n;
    int min, max;
    printf("Enter the no of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements of array: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[n]);
    }

    return 0;
}
