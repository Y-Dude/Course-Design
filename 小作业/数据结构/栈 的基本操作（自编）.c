#include<stdio.h>
#define SELemtype int;
#define STACK_SIZE 100;
#define INCREMENT 10;
struct sqstack
{
    SElemtype *base;
    SElemtype *top;
    int stacksize;
};
int Initstack(sqstack &s)
{
    s.base=(SElemtype *)malloc(STACK_SIZE * sizeof(SElmtype));
    if(!s.base) exit(OVERFLOW);
    s.top=s.base;
    s.stacksize=STACK_SIZE;
    return OK;
}
int Gettop(sqtack s,SElemtype &e)
{
    if(s.top==s.base) return ERROR;
    e=*(s.top-1);
    return OK;
}
int push(sqstack &s,SElemtype e)
{
    if(s.top-s.base>=s.stacksize)
    {
        s.base=(SElemtype *)realloc(s.base,(s.stacksize+INCREMENT)*sizeof(SElemtype));
        if(!s.base) exit (OVERLOW);
        s.top=s.base+s.stacksize;
        s.stacksize=s.stacksize+STACKINCRENT;
    }
    *s.top=e;
    s.top++;
    return OK;
}
int pop(sqstack &s,SElemtype &e)
{
    if(s.top==s.base) return ERROR;
    e=*--s.top;
}
int main()
{

}
