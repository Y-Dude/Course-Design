#include<stdio.h>
int main()
{
    int i,j,k,r,s=0,q=0,m,n,a[300],b[100];
    while(scanf("%d",&m)!=EOF)
    {
        for(i=0;i<m;i++)
            scanf("%d",&a[i]);
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);
            for(i=0;i<m;i++){
                    if(i==0)
                    printf("%d",a[i]);
                    else
                        printf(" %d",a[i]);
            }
            printf("\n");
            for(i=0;i<n;i++) {
                    if(i==0)
                    printf("%d",b[i]);
                    else
                        printf(" %d",b[i]);
            }
            printf("\n");
            for(i=m,j=0;j<n;j++)
            {
                for(r=0;r<m;r++)
                    if(a[r]==b[j])
                    s++;
                if(s==0){
                a[i]=b[j];
                for(k=0;k<m+q+1;k++)
                    {
                        if(k==0)
                            printf("%d",a[k]);
                        else
                            printf(" %d",a[k]);
                        }
                printf("\n");
                q++;i++;}
                else{
                    for(k=0;k<m+q;k++)
                    {
                        if(k==0)
                            printf("%d",a[k]);
                        else
                            printf(" %d",a[k]);
                        }
                    printf("\n");
                }
                s=0;
            }
            q=0;
            printf("\n");
    }
    return 0;
}
