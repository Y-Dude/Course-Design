#include<stdio.h>
#define LEAP_YEAR(y)(((y%4==0&&y%100!=0)||(y%400==0))?'L':'N')
int main()
{
    char c;
    int y;
    scanf("%d",&y);
    c=LEAP_YEAR(y);
    printf("%c",c);
    return 0;
}
