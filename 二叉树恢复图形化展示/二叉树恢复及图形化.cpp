#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAXNODE 100


#include <windows.h>            ///�Զ������ƶ���������굽ָ��λ�����꣨x,y��
static void   gotoxy(int   x,   int   y)   {
  COORD   c;
  c.X   =   x   -   1;
  c.Y   =   y   -   1;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

typedef struct Node{
	char data;
	struct Node* lchild;
	struct Node* rchild;
}*BiTree;

void Init(BiTree *T){
        (*T) = (BiTree)malloc(sizeof(Node));
        (*T)->lchild=NULL;
		(*T)->rchild=NULL;
}


void Destroy(BiTree *T){
	if(*T == NULL)
		return ;
	Destroy(&((*T)->lchild));
	Destroy(&((*T)->rchild));
	free(*T);
	*T = NULL;
}


//ͼ�����
/*
	����������Ϊģ�������
	����������ߵ�Ҷ�ӵ����ڵ��ˮƽ����Ϊ�����ڵ��������Ľڵ����.2^(k-2) k�ǲ��� ���Ĳ���Ϊ1
*/
int x0=0;
int y0=6;
void print(BiTree T,int level){//T,1

   x0++;
   if(T == NULL)
		return ;
    else
    {
		print(T->lchild,level+1);Sleep(1000);
		gotoxy(x0,(level*2)+y0);
		printf("%c",T->data);
		if(T->lchild!=NULL){
			gotoxy(x0-1,(level*2)+y0+1);Sleep(1000);
			printf("/");
		}
		if(T->rchild!=NULL){
			gotoxy(x0+1,(level*2)+y0+1);Sleep(1000);
			printf("\\");
		}
		print(T->rchild,level+1);Sleep(1000);
	}
}
///�����ַ���λ��
int getIndex(char *str,char x){
	int i;
	for(i=0;i<strlen(str);i++){
		if(str[i]==x){
			return i;
		}
	}
	return -1;
}
///��str�ַ����ָ�
void getFastEnd(char *str,char x,char result[2][100]){
	strcpy(result[0],"\0");
	strcpy(result[1],"\0");
	if(strlen(str)==0 || strlen(str)==1){
		return;
	}
	if(getIndex(str,x) == 0){
		strcpy(result[1],str+1);
	}else if(getIndex(str,x) == strlen(str)-1){
		strcpy(result[0],str);
		result[0][strlen(str)-1]='\0';
	}else{
		strcpy(result[0],strtok(str,&x));               ///strtok��str��&x����str�ַ�����x֮ǰ���ַ�������
		strcpy(result[1],strtok(NULL,&x));              ///strtok��NULL��&x����str�ַ�����x֮����ַ�������
	}
}

///����ǰ�����������һ�Ŷ�����
int fIndex=0;      //��ʶǰ����д���
void getTreeForP_I(char *proOrder,char *inOrder,BiTree *T){
    BiTree temp=NULL;
	char result[2][100];      //�洢���Һ��ӵ���������
	if(*inOrder==NULL){	      //����������Ϊ��ʱ��ָ���������ָ������ΪNULL
		*T = NULL;
	}else{
        Init(&temp);
		temp->data = proOrder[fIndex++];
		*T = temp;
		getFastEnd(inOrder,temp->data,result);	   //���������и��ݵ�ǰ����ֵ�ָ������
		getTreeForP_I(proOrder,result[0],&(temp->lchild));   //�ָ�������
		getTreeForP_I(proOrder,result[1],&(temp->rchild));   //�ָ�������
	}
}

///���� �������������һ�Ŷ�����
int eIndex=1;
void getTreeForI_E(char *endOrder,char *inOrder,BiTree *T){
    BiTree temp=NULL;
	char result[2][100];
	if(*inOrder==NULL){
		*T=NULL;
	}else{
        Init(&temp);
		temp->data = endOrder[strlen(endOrder)-eIndex++];
		*T = temp;
		getFastEnd(inOrder,temp->data,result);	//���������и��ݵ�ǰ����ֵ�ָ������
		getTreeForI_E(endOrder,result[1],&(temp->rchild));//�ָ�������
		getTreeForI_E(endOrder,result[0],&(temp->lchild));//�ָ�������
	}
}


void JM()
{
    printf("***************************************************\n");
    printf("**   1.���������ǰ�������ַ����л���������    **\n");
    printf("**   2.������������򣬺����ַ����л���������    **\n");
    printf("**   0.�˳�                                      **\n");
    printf("***************************************************\n");
}

int main()
{
    int a=1;
	while(a)
    {
	char pro[MAXNODE];
	char in[MAXNODE];
	char en[MAXNODE];
    BiTree T=NULL;
	JM();
	scanf("%d",&a);
	system("cls");
	switch(a)
	{
	    case 1:
	        {
	            printf("������ǰ���ַ����У�");scanf("%s",pro);
	            printf("�����������ַ����У�");scanf("%s",in);
	            getTreeForP_I(pro,in,&T);
                printf("\nͼ�������");
                print(T,1);printf("\n"); getch();
	        }break;
        case 2:
            {
                printf("�����������ַ����У�");scanf("%s",in);
                printf("����������ַ����У�");scanf("%s",en);
                getTreeForI_E(en,in,&T);
                printf("\nͼ�������");
                print(T,1);printf("\n");getch();
            }break;
	}
	Destroy(&T);
	fIndex=0;         //������ȫ�ֱ�������
    eIndex=1;
	x0=0;
	y0=6;
	system("cls");
    }
    return 0;
}
