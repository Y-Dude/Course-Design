#include<stdio.h>
int zs(int x)
{
    int j;
    for(j=2;j<=x/2;j++)
    {
        if(x%j==0) return 0;
    }
    return 1;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(zs(a[i])==1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
