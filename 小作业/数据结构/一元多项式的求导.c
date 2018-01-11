#include<stdio.h>
int main()
{
    int a[1000],x[1000];
    int i=-1,j=0;
    a[0]=x[0]=0;
    while(a[i]!=-1&&x[i]!=-1)
        {
            i++;
            scanf("%d %d",&a[i],&x[i]);
        }
    for(j=0;j<=i-1;j++)
    {
        if(x[j]!=0)
      {a[j]=a[j]*x[j];
      x[j]=x[j]-1;}
      else
      {a[j]=a[j]*x[j];
      x[j]=0;}
    }
    for(j=0;j<=i-1;j++)
    {
        if(a[j]!=0)
            printf("%d %d ",a[j],x[j]);
            else
                printf("0");
    }
    printf("\n");
    return 0;
}
