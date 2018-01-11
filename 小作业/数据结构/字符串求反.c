#include<stdio.h>
#include<string.h>
int main()
{
    int i=0,j=0,x;
    char s1[11],s2[11];
    gets(s1);
    x=strlen(s1);
    printf("%d\n",x);
    for(i=x-1;i>=0;i--)
    {s2[j]=s1[i];j++;}
    for(j=0;j<=x-1;j++)
        printf("%c",s2[j]);
    return 0;
}
