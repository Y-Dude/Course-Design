#include<stdio.h>
int main()
{
    char a[200000000],b[20000000];
    int i,k,n=0;
    while(scanf("%s",&a)!=EOF)
    {
        printf(" ");scanf("%s",&b);
        for(i=0;a[i]!='\0'&&b[i]!='\0';i++)
        {
            if(a[i]==b[i]) {printf("%d",i);break;}
            else {n++;k=-1;}
        }
        if(n==i) printf("%d",k);
        printf("\n");
    }
    return 0;
}
