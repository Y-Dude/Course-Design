#include<stdio.h>
#define max(x,y,z)(x>y?(x>z?x:z):(y>z?y:z))
int Max(float x,float y,float z)
{
    if(x>y)
        x=x;
    else x=y;
    if(x>z)
        x=x;
    else x=z;
    return x;
}
int main()
{
   float a,b,c,m1,m2;
   scanf("%f %f %f",&a,&b,&c);
   m1=Max(a,b,c);
   m2=max(a,b,c);
   printf("%.3f\n",m1);
   printf("%.3f\n",m2);
   return 0;
}
