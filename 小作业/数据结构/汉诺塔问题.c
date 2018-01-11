#include<stdio.h>
int i=1;
int move(int n,int x,int y,int z)
{
    if(n==1) {
            printf("%2d. Move disk %d from %c to %c\n",i,n,x,z);i++;}
    else{
        move(n-1,x,z,y);
        printf("%2d. Move disk %d from %c to %c\n",i,n,x,z);
        i++;
        move(n-1,y,x,z);
    }
    return 0;
}
int main()
{
    int h;
    while(scanf("%d",&h)!=EOF){
    move(h,'X','Y','Z');
    printf("\n");
    i=1;
    }
    return 0;
}
