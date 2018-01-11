#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        if(a+b<=c||a+c<=b||b+c<=a) printf("ERROR\n");
        else if(a==b&&a==c) printf("DB\n");
        else if(a==b||a==c||b==c) printf("DY\n");
        else if(a*a+b*b==c*c||a*a+c*c==b*b||c*c+b*b==a*a) printf("ZJ\n");
        else printf("PT\n");
    }
    return 0;
}
