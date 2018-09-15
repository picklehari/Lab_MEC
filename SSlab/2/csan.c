#include<stdio.h>
#include<stdlib.h>

void sort(int n, int a[])
{
    int t;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
    }
}

int main()
{
    int n, a[30], h, total = 0, max, pos = 0, i;

    printf("\nNo of head position: ");
    scanf("%d",&max);

    printf("Enter position of head: ");
    scanf("%d",&a[0]);
    h = a[0];

    printf("Enter no of locations: ");
    scanf("%d",&n);

    printf("Enter locations: ");
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    sort(n+1,a);


    printf("Disk Head Movement:\n");
    while(a[pos] != h) pos++;
    
    for(i=pos;i<=n;i++)
        printf("%d --> ",a[i]);
    

    if(a[i-1] != max-1)
        printf("%d --> ",max-1);

    total += max-1 - h;

    for(i=pos-1;i>=0;i--)
        printf("%d --> ",a[i]);

    if(pos != 0)
        total += max-1 - a[0];

    printf("\nTotal disk head movement: %d\n\n", total);
}
