#include<stdio.h>
int main()
{
    int a1[1000],b1[1000],a2[1000],b2[1000],x[1000],y[1000],n1,n2,k=0,i=-1,j=-1;
    a1[0]=b1[0]=a2[0]=b2[0]=0;
    while(a1[i]!=-1&&b1[i]!=-1)
    {
        i++;
        scanf("%d %d",&a1[i],&b1[i]);
    }
    while(a2[j]!=-1&&b2[j]!=-1)
    {
        j++;
        scanf("%d &d",&a2[j],&b2[j]);
    }
    for(n1=0;n1<i;n1++)
    {
        for(n2=0;n2<j;n2++)
        {
            x[k]=a1[n1]*a2[n2];
            y[k]=b1[n1]+b2[n2];
            k++;
        }
    }
    /*for(i=0;i<k;)
    {
        if(y[i]=y[i+1]){
            x[i]=x[i]+x[i+1];
            x[i+1]=x[i+2];
            y[i+1]=y[i+2];}
            else{
                    i++;
                    j=i;}
    }*/
    for(i=0;i<k;i++)
    {
        printf("%d %d ",x[i],y[i]);
    }
    return 0;
}
