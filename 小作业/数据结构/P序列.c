#include <stdio.h>
#include <string.h>
int main(void)
{
    int m;
    char b[1000];
    char a[1000];
    while(scanf("%s",&b)!=EOF)
    {
        strcpy(a,b);
        int i=1,j,n=0;
        int b[100]={0},c[100]={0};
        while(a[i]!='\0')
        {
            if(a[i]=='(')
               {
                   b[i]=1;
               }
               else
               {
                   c[i]=1;
               }
               i++;
        }
        for(i=1;i<100;i++)
        if(c[i]==1)
        {
            for(j=i-1;j>0;j--)
            if(b[j]==1)
            {
                b[j]=0;
                break;
            }
            for(m=j;m<=i;m++)
            if(c[m]==1)
            n++;
            printf("%d ",n);
            n=0;
        }
        printf("\n");
    }
}
