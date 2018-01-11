#include<stdio.h>
int main()
{
    int a,b[50],k=-1,i;
    while(scanf("%d",&a)!=EOF)
    {
        for(i=0;a!=0;i++)
        {
            b[i]=a%8;
            a=a/8;
            k++;
        }
        for(i=k;i>=0;i--)
        {
            printf("%d",b[i]);
        }
        printf("\n");
        k=-1;
    }
    return 0;
}
