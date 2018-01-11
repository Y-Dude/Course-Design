#include<stdio.h>
int main()
{
    float a,b;
    int c;
    while(scanf("%f %f",&a,&b)!=EOF)
    {
        if(b==0) printf("error\n");
        else {c=a/b+0.5;printf("%d\n",c);}
    }
    return 0;
}
