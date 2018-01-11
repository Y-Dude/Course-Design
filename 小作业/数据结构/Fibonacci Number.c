#include<stdio.h>
int main()
{
    int f=0,f1=0,f2=1,t,i,j,a[100],x=0;
    scanf("%d",&t);
    for(j=0;j<t;j++)
        scanf("%d",&a[j]);
    for(j=0;j<t;j++)
        {
            for(i=0;i<a[j];i++)
                {
                    f=f1+f2;
                    x=f2;
                    f1=f2;f2=f;
                }
        printf("%d\n",x);
        f1=0;f2=1;
        }
        return 0;
}
