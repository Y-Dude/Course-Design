#include<stdio.h>
int main()
{
    int N,n,i,j;
    scanf("%d",&n);
    N=n;
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            for(j=i;j<n;j++)
            a[j]=a[j+1];
            N--;
        }
    }
    printf("%d\n",N);
    for(i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
#include<stdio.h>

int main()
{
    int m,k,n,i,j,a[105],b[105],l,s;
    scanf("%d",&m);
    for(k=0;k<m;k++)
    {
        scanf("%d",&n);
        s=0;
        l=n;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                l--;
                for(j=i+1;j<n;j++)
                {
                    s+=a[j];
                }
            }
        }
        printf("%d %d",s,l);
        for(i=0;i<n;i++)
        {
            if(a[i]!=0)
            {
                printf(" %d",a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
