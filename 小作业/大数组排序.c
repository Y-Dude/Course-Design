#include<stdio.h>
#include<malloc.h>
int main()
{
    int i,j,t,n;
    scanf("%d",&n);
    while(n!=0)
    {
    int *a=(int *)malloc(2000000*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
    {
        if(a[j+1]<a[j])
        {t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;}
    }
    for(i=0;i<n;i++)
    {
        if(i==n) printf("%d",a[n]);
        else printf("%d ",a[i]);
    }
    printf("\n");
    free(a);
    scanf("%d",&n);
    }
    return 0;
}
