#include<stdio.h>
#include<string.h>
struct name
{
    char a[30];
};
struct name s[100];
int main()
{
    char str[6],a1[30];
    int m=1,n,i,k;
    while(scanf("%s",&str)!=EOF)
    {
        if(strcmp(str,"insert")==0)
        {
            scanf("%d",&n);
            for(i=m;i>=n;i--)
                strcpy(s[i].a,s[i-1].a);
            scanf("%s",&s[n].a);
            m++;
        }
        else if(strcmp(str,"delete")==0)
        {
            scanf("%s",&a1);
            for(i=1;i<m;i++)
                if(strcmp(s[i].a,a1)==0)
                k=i;
            for(i=k;i<m-1;i++)
                strcpy(s[i].a,s[i+1].a);
            m--;
        }
        else if(strcmp(str,"show")==0)
        {
            for(i=1;i<m;i++)
            {
                if(i==1)
                    printf("%s",s[i].a);
                else
                printf(" %s",s[i].a);
            }
            printf("\n");
        }
        else if(strcmp(str,"search")==0)
        {
            scanf("%s",&a1);
            for(i=1;i<m;i++)
                if(strcmp(s[i].a,a1)==0)
                k=i;
                printf("%d\n",k);
        }
    }
    return 0;
}
