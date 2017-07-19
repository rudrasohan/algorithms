#include <stdio.h>

void merge(int a[],int l,int m,int r)
{
    int i,j,k,l1,l2;
    l1 = m - l+1;
    l2 = r - m;
    int L[l1],R[l2];
    for(i=0;i<l1;i++)
    {
        L[i] = a[i+l];
    }
    for(j=0;j<l2;j++)
    {
        R[j] = a[j+m+1];
    }
    i = 0,j = 0,k=l;
    while((i<l1)&&(j<l2))
    {
        if(L[i]<=R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<l1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<l2)
    {
        a[k] = R[j];
        j++;
        k++;
    }

}

void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid = l+(r-l)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

int main()
{
    int n,i;
    printf("Enter the Length of the Array\n");
    scanf("%d",&n);
    int a[n];

    printf("\nEnter Elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n");

    printf("Unsorted Array\n");
    for (i = 0; i < n; i++)
    {
        printf("%d,",a[i]);
    }
    printf("\n");

    mergesort(a,0,n-1);

    printf("Sorted Array\n");
    for (i = 0; i < n; i++)
    {
        printf("%d,",a[i]);
    }
    printf("\n");
    return 0;
}