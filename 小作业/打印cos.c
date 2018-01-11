#include<stdio.h>
#include<math.h>
int main()
{
    double y;
    int m,x;
    for(y=1;y>=-1;y=y-0.1)
    {
        m=acos(y)*10;
        for(x=1;x<m;x++)
        printf(" ");
    printf("*");
        for(;x<60-m;x++)
        printf(" ");
    printf("*\n");
    }
}
