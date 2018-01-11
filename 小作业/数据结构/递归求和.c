#include<stdio.h>
int main()
{
    int i,f,n;
    f=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        f=f+i;
    }
    printf("%d",f);
}
