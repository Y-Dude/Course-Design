#include<stdio.h>
int main()
{
    int a,b,i,s[7],M=8,k=0;
    for(i=0;i<7;i++)
    {
        scanf("%d %d",&a,&b);
        s[i]=a+b;
    }
    for(i=0;i<7;i++)
        {
            if(s[i]>M) {M=s[i];k=i+1;}
        }
    printf("%d",k);
    return 0;
}
