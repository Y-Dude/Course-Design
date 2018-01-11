#include<stdio.h>
struct LB
{
    int a;
    struct LB*next;
};
struct LB s[100];
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
                printf("list is empty\n");}
        else{for(i=0;i<n;i++)
    {
        scanf("%d",&s[i].a);
        s[i].next=&s[i+1];
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",s[i].a);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(s[i].a==s[i+1].a)continue;
        printf("%d ",s[i].a);
    }
    printf("\n");}}
    return 0;
}
