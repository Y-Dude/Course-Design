//顺序栈
#include<stdio.h>

#include<stdlib.h>

#include<malloc.h>

#define STACK_INIT_SIZE 100;

#define STACKINCREMENT 10;

typedef struct
{
int *base;
int *top;
int stacksize;
}SqStack;

typedef int ElemType;

int InitStack(SqStack &S) //为栈S分配存储空间，并置S为空栈
{
int size = STACK_INIT_SIZE;
S.base=(int *)malloc(size*sizeof(ElemType));
if(!S.base)
return 0;
S.top=S.base; //置栈S为空栈
S.stacksize=STACK_INIT_SIZE;
return 1;
}

int GetTop(SqStack S,int &e) //若栈不空，则用e返回S的栈顶元素
{
if(S.top==S.base) return 0;
e=*(S.top-1);
return 1;

}

int Push(SqStack &S, int e) /*进栈函数,将e插入栈S中,并使之成为栈顶元素*/
{ if(S.top-S.base>=S.stacksize) /*栈满，追加存储空间*/
{
int stackinvrement = STACKINCREMENT;

S.base=(ElemType *) realloc(S.base,(S.stacksize+stackinvrement)*sizeof(ElemType));
if(!S.base)
return 0; /*存储分配失败*/
S.stacksize+=STACKINCREMENT;
}

*S.top++=e;
return 1;
}

int Pop(SqStack &S,int &e)/*出栈函数,若栈S不空,则删除S的栈顶元素,用e返回其值*/

{ if(S.top==S.base) return 0;

e=*--S.top;
return 1;
}

void OutputStack(SqStack &S)

{int *q;
q=S.top-1;
for(int i=0;i<S.top-S.base;i++)
{

printf("%3d ",*q);q--;}

}

void main()

{

int a,b,c ;
char m;

SqStack s;

InitStack(s);
printf("请输入要进栈的元素个数是:");

scanf("%d",&a);

printf("\n请输入要进栈的%d个元素:",a);

for(b=0;b<a;b++) {
scanf("%d",&c);
Push(s,c); }
do { printf("\n");
printf("*********** 1.输出栈的元素**********\n");
printf("*********** 2.取栈顶元素************\n");
printf("*********** 3.删除栈顶元素**********\n");
printf("*********** 4.退出程序**********\n");
printf("\n请选择一个字符:");
getchar();
scanf("%c",&m);
switch(m) {
case '1': printf("\n输出的栈为:");
OutputStack(s);
break;

case '2': GetTop(s,c);
printf("\n栈顶元素为:%d",c);
printf("\n输出的栈为:");
OutputStack(s);
break;
case '3': Pop(s,c);
printf("\n删除的栈顶元素:%d",c);
printf("\n输出的栈为:");
OutputStack(s);
printf("\n");
break;
case '4':break;
default: printf("输入的数字有错，请重新选择!\n"); break;

}

}while(m!='4');

}
//链栈

#include<stdio.h>
#include<stdlib.h>
typedef struct SNode
{
int data;
struct SNode *next;
}SNode,*LinkStack;
LinkStack top;
LinkStack PushStack(LinkStack top,int x) //入栈
{
LinkStack s;
s=(LinkStack)malloc(sizeof(SNode));
s->data=x;
s->next=top;
top=s;
return top;
}
LinkStack PopStack(LinkStack top) //退栈
{
LinkStack p;
if(top!=NULL)
{
p=top;
top=top->next;
free(p);
printf("退栈已完成\n");
return top;
}
else printf("栈是空的，无法退栈！\n"); return 0;
}
int GetStackTop(LinkStack top) //取栈顶元素
{
return top->data;

}
bool IsEmpty()//bool取值false和true，是0和1的区别,bool只有一个字节,BOOL为int型,bool为布尔型

{
return top==NULL ? true:false;
}
void Print()
{
SNode *p;
p=top;
if(IsEmpty())
{
printf("The stack is empty!\n");
return;
}
while(p)
{
printf("%d ", p->data);
p=p->next;
}
printf("\n");
}

void main()
{

int x,a,b;
char m;
do { printf("\n");
printf("###############链栈的基本操作##################\n");
printf("××××××××1.置空栈××××××××××\n");
printf("××××××××2.进栈×××××××××××\n");
printf("××××××××3.退栈×××××××××××\n");
printf("××××××××4.取栈顶元素××××××××\n");
printf("××××××××5.退出程序×××××××××\n");
printf("##############################################\n");
printf("\n请选择一个字符:");
scanf("%c",&m);
switch(m){
case '1':
top=NULL;
printf("\n栈已置空!");
break;
case '2':
printf("\n请输入要进栈的元素个数是:");
scanf("%d",&a);
printf("\n请输入要进栈的%d个元素:",a);
for(b=0;b<a;b++) {
scanf("%d",&x);
top=PushStack(top,x); }
printf("进栈已完成！\n");
printf("\n输出栈为:");
Print();
break;
case '3':
printf("\n操作之前的输出栈为:");
Print();
top=PopStack(top);
printf("\n操作过后的输出栈为:");
Print();
break;
case '4':
printf("\n输出栈为:");
Print();
if(top!=NULL)
printf("\n栈顶元素是：%d\n",GetStackTop(top));
else
printf("\n栈是空的，没有元素！");
break;
case '5':break;
default:
printf("\n输入的字符不对，请重新输入!");
break;

}
getchar();
}while(m!='5');

}
#include <stdio.h>
#include <stdlib.h>
#define MAX 1024 ///栈使用数组模拟，MAX是最大元素个数
typedef int DataType; ///数据域使用整形

typedef struct _stack
{
DataType data[MAX]; ///存放数据
int top; ///栈顶指针
}stack;

///初始化
int initStack(stack (*s))
{
return emptyStack(s);
}

///数据压栈，成功返回1，失败返回0
int push(stack (*s), DataType d)
{
if ((*s).top >= MAX - 1) //栈已满
{
printf("栈已满，不能压栈\n");
return 0;
}

//数据压栈
(*s).top++;
(*s).data[(*s).top] = d;
return 1;
}

///数据出栈，成功返回1，d指向的区域存储弹出的数据，失败返回0
int pop(stack (*s), DataType *d)
{
if ((*s).top <= -1)
{
printf("栈为空，不能出栈\n");
return 0;
}

//出栈
*d = (*s).data[(*s).top];
(*s).top--;
return 1;
}

///清空栈
int emptyStack(stack (*s))
{
(*s).top = -1;
return 1;
}

int main(int argc, char** argv)
{
stack s;
int i, d;

initStack(&s);

//压栈
for (i = 0; i < 1025; i++)
{
push(&s, i);
}

//清空
emptyStack(&s);

for (i = 0; i < 10; i++)
{
push(&s, i);
}
//出栈
for (i = 0; i < 11; i++)
{
pop(&s, &d);
printf("%d\n", d);
}

return 0;
}
