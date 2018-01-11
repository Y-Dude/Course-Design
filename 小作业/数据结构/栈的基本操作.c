//˳��ջ
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

int InitStack(SqStack &S) //ΪջS����洢�ռ䣬����SΪ��ջ
{
int size = STACK_INIT_SIZE;
S.base=(int *)malloc(size*sizeof(ElemType));
if(!S.base)
return 0;
S.top=S.base; //��ջSΪ��ջ
S.stacksize=STACK_INIT_SIZE;
return 1;
}

int GetTop(SqStack S,int &e) //��ջ���գ�����e����S��ջ��Ԫ��
{
if(S.top==S.base) return 0;
e=*(S.top-1);
return 1;

}

int Push(SqStack &S, int e) /*��ջ����,��e����ջS��,��ʹ֮��Ϊջ��Ԫ��*/
{ if(S.top-S.base>=S.stacksize) /*ջ����׷�Ӵ洢�ռ�*/
{
int stackinvrement = STACKINCREMENT;

S.base=(ElemType *) realloc(S.base,(S.stacksize+stackinvrement)*sizeof(ElemType));
if(!S.base)
return 0; /*�洢����ʧ��*/
S.stacksize+=STACKINCREMENT;
}

*S.top++=e;
return 1;
}

int Pop(SqStack &S,int &e)/*��ջ����,��ջS����,��ɾ��S��ջ��Ԫ��,��e������ֵ*/

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
printf("������Ҫ��ջ��Ԫ�ظ�����:");

scanf("%d",&a);

printf("\n������Ҫ��ջ��%d��Ԫ��:",a);

for(b=0;b<a;b++) {
scanf("%d",&c);
Push(s,c); }
do { printf("\n");
printf("*********** 1.���ջ��Ԫ��**********\n");
printf("*********** 2.ȡջ��Ԫ��************\n");
printf("*********** 3.ɾ��ջ��Ԫ��**********\n");
printf("*********** 4.�˳�����**********\n");
printf("\n��ѡ��һ���ַ�:");
getchar();
scanf("%c",&m);
switch(m) {
case '1': printf("\n�����ջΪ:");
OutputStack(s);
break;

case '2': GetTop(s,c);
printf("\nջ��Ԫ��Ϊ:%d",c);
printf("\n�����ջΪ:");
OutputStack(s);
break;
case '3': Pop(s,c);
printf("\nɾ����ջ��Ԫ��:%d",c);
printf("\n�����ջΪ:");
OutputStack(s);
printf("\n");
break;
case '4':break;
default: printf("����������д�������ѡ��!\n"); break;

}

}while(m!='4');

}
//��ջ

#include<stdio.h>
#include<stdlib.h>
typedef struct SNode
{
int data;
struct SNode *next;
}SNode,*LinkStack;
LinkStack top;
LinkStack PushStack(LinkStack top,int x) //��ջ
{
LinkStack s;
s=(LinkStack)malloc(sizeof(SNode));
s->data=x;
s->next=top;
top=s;
return top;
}
LinkStack PopStack(LinkStack top) //��ջ
{
LinkStack p;
if(top!=NULL)
{
p=top;
top=top->next;
free(p);
printf("��ջ�����\n");
return top;
}
else printf("ջ�ǿյģ��޷���ջ��\n"); return 0;
}
int GetStackTop(LinkStack top) //ȡջ��Ԫ��
{
return top->data;

}
bool IsEmpty()//boolȡֵfalse��true����0��1������,boolֻ��һ���ֽ�,BOOLΪint��,boolΪ������

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
printf("###############��ջ�Ļ�������##################\n");
printf("����������������1.�ÿ�ջ��������������������\n");
printf("����������������2.��ջ����������������������\n");
printf("����������������3.��ջ����������������������\n");
printf("����������������4.ȡջ��Ԫ�ء���������������\n");
printf("����������������5.�˳����������������������\n");
printf("##############################################\n");
printf("\n��ѡ��һ���ַ�:");
scanf("%c",&m);
switch(m){
case '1':
top=NULL;
printf("\nջ���ÿ�!");
break;
case '2':
printf("\n������Ҫ��ջ��Ԫ�ظ�����:");
scanf("%d",&a);
printf("\n������Ҫ��ջ��%d��Ԫ��:",a);
for(b=0;b<a;b++) {
scanf("%d",&x);
top=PushStack(top,x); }
printf("��ջ����ɣ�\n");
printf("\n���ջΪ:");
Print();
break;
case '3':
printf("\n����֮ǰ�����ջΪ:");
Print();
top=PopStack(top);
printf("\n������������ջΪ:");
Print();
break;
case '4':
printf("\n���ջΪ:");
Print();
if(top!=NULL)
printf("\nջ��Ԫ���ǣ�%d\n",GetStackTop(top));
else
printf("\nջ�ǿյģ�û��Ԫ�أ�");
break;
case '5':break;
default:
printf("\n������ַ����ԣ�����������!");
break;

}
getchar();
}while(m!='5');

}
#include <stdio.h>
#include <stdlib.h>
#define MAX 1024 ///ջʹ������ģ�⣬MAX�����Ԫ�ظ���
typedef int DataType; ///������ʹ������

typedef struct _stack
{
DataType data[MAX]; ///�������
int top; ///ջ��ָ��
}stack;

///��ʼ��
int initStack(stack (*s))
{
return emptyStack(s);
}

///����ѹջ���ɹ�����1��ʧ�ܷ���0
int push(stack (*s), DataType d)
{
if ((*s).top >= MAX - 1) //ջ����
{
printf("ջ����������ѹջ\n");
return 0;
}

//����ѹջ
(*s).top++;
(*s).data[(*s).top] = d;
return 1;
}

///���ݳ�ջ���ɹ�����1��dָ�������洢���������ݣ�ʧ�ܷ���0
int pop(stack (*s), DataType *d)
{
if ((*s).top <= -1)
{
printf("ջΪ�գ����ܳ�ջ\n");
return 0;
}

//��ջ
*d = (*s).data[(*s).top];
(*s).top--;
return 1;
}

///���ջ
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

//ѹջ
for (i = 0; i < 1025; i++)
{
push(&s, i);
}

//���
emptyStack(&s);

for (i = 0; i < 10; i++)
{
push(&s, i);
}
//��ջ
for (i = 0; i < 11; i++)
{
pop(&s, &d);
printf("%d\n", d);
}

return 0;
}
