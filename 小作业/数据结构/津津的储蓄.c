#include<stdio.h>
int main()
{
    int a[12],i=0,x=300,s=0;
    for(i=0;i<12;i++)
        scanf("%d",&a[i]);
    for(i=0;i<12;i++)
        {
        if(x<a[i])
        {i=-i-1;printf("%d",i);break;}
        x=x-a[i];
        if(x<100)
        {x=x+300;continue;}
        if(x>=100&&x<200)
        {x=x-100;s=s+100;x=x+300;continue;}
        if(x>=200&&x<300)
        {x=x-200;s=s+200;x=x+300;continue;}
        if(x>=300)
        {x=x-300;s=s+300;x=x+300;continue;}
        }
        s=s+0.2*s+x-300;
        if(i>=11)
            printf("%d",s);
        return 0;
}
