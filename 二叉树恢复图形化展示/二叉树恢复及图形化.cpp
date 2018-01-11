#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAXNODE 100


#include <windows.h>            ///自定义光标移动函数将光标到指定位置坐标（x,y）
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


//图像输出
/*
	以满二叉树为模型输出：
	二叉树最左边的叶子到根节点的水平距离为：根节点左子树的节点个数.2^(k-2) k是层数 根的层数为1
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
///查找字符的位置
int getIndex(char *str,char x){
	int i;
	for(i=0;i<strlen(str);i++){
		if(str[i]==x){
			return i;
		}
	}
	return -1;
}
///将str字符串分割
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
		strcpy(result[0],strtok(str,&x));               ///strtok（str，&x）把str字符串中x之前的字符串返回
		strcpy(result[1],strtok(NULL,&x));              ///strtok（NULL，&x）把str字符串中x之后的字符串返回
	}
}

///依据前序和中续生成一颗二叉树
int fIndex=0;      //标识前序进行次数
void getTreeForP_I(char *proOrder,char *inOrder,BiTree *T){
    BiTree temp=NULL;
	char result[2][100];      //存储左右孩子的中序序列
	if(*inOrder==NULL){	      //当中序序列为空时将指向该子树的指针设置为NULL
		*T = NULL;
	}else{
        Init(&temp);
		temp->data = proOrder[fIndex++];
		*T = temp;
		getFastEnd(inOrder,temp->data,result);	   //将中序序列根据当前根的值分割成两段
		getTreeForP_I(proOrder,result[0],&(temp->lchild));   //恢复左子树
		getTreeForP_I(proOrder,result[1],&(temp->rchild));   //恢复右子树
	}
}

///依据 后序和中序生成一颗二叉树
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
		getFastEnd(inOrder,temp->data,result);	//将中序序列根据当前根的值分割成两段
		getTreeForI_E(endOrder,result[1],&(temp->rchild));//恢复右子树
		getTreeForI_E(endOrder,result[0],&(temp->lchild));//恢复左子树
	}
}


void JM()
{
    printf("***************************************************\n");
    printf("**   1.输入二叉树前序，中序字符序列画出二叉树    **\n");
    printf("**   2.输入二叉树中序，后序字符序列画出二叉树    **\n");
    printf("**   0.退出                                      **\n");
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
	            printf("请输入前序字符序列：");scanf("%s",pro);
	            printf("请输入中序字符序列：");scanf("%s",in);
	            getTreeForP_I(pro,in,&T);
                printf("\n图像输出：");
                print(T,1);printf("\n"); getch();
	        }break;
        case 2:
            {
                printf("请输入中序字符序列：");scanf("%s",in);
                printf("请输入后序字符序列：");scanf("%s",en);
                getTreeForI_E(en,in,&T);
                printf("\n图像输出：");
                print(T,1);printf("\n");getch();
            }break;
	}
	Destroy(&T);
	fIndex=0;         //把所有全局变量重置
    eIndex=1;
	x0=0;
	y0=6;
	system("cls");
    }
    return 0;
}
