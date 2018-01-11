#include<stdio.h>
#include<string.h>
int main()
{
    int n,k=0,m,i,j,l=0;
    char a[1000],b[1000];
    scanf("%d",&n);
    while(k!=n)
    {
        scanf("%s",&a);
        m=strlen(a);
        for(i=m-1,j=0;i>=0;i--,j++)
            b[j]=a[i];
            for(i=0;a[i]!='\0';i++)
            {
                if(a[i]==b[i]) l++;
                else {printf("NO");break;}
            }
            if(l==m) printf("YES");
            printf("\n");k++;l=0;
    }
    return 0;
}
