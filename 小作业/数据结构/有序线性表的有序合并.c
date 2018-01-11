#include<stdio.h>
int main()
{
    int i,j,n,m,a[200],b[100],t;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d",&b[i]);
        for(i=n,j=0;j<m;i++,j++)
            a[i]=b[j];
        for(i=0;i<m+n;i++)
            for(j=i+1;j<m+n;j++)
            {
                if(a[i]>a[j]){
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        for(i=0;i<m+n;i++)
        {
            if(i==0)
                printf("%d",a[i]);
            else
                printf(" %d",a[i]);
        }
            printf("\n");
    }
    return 0;
}
