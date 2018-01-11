#include <iostream>
using namespace std;
#define STACK_INIT_SIZE 100
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchid, *rchild;
}BiTNode, *BiTree;				        //二叉树结构体
typedef struct
{
	BiTNode *Sdata[STACK_INIT_SIZE];	//二叉树节点存放处
	int Sflag[STACK_INIT_SIZE];		    //记录Stop处是否有二叉树节点
	int Stop;						    //Sdata位移记录数
}SqStack, *SqStackPr;
typedef struct
{
	BiTNode *Qdata[STACK_INIT_SIZE];
	int front;
	int rear;
}QNode, *QueuePtr;
bool creatBiTree(BiTree &T)
	//按先序次序输入二叉树中的节点值
{
	char _data;
	cin>>_data;
	BiTree p=T;					        //记录T当前所指节点
	if(_data=='#')
	{
		T=NULL;
	}
	if(_data=='#')
	{
		p->rchild=NULL;
		return true;
	}
	if(_data!='#')
	{
		if(!(T=new BiTNode))
		{
			cout<<"\n内存空间不足，二叉树节点创建失败！";
			return false;
		}
		T->data=_data;
		T->lchid=new BiTNode;
		T->rchild=new BiTNode;
		creatBiTree(T->lchid);
		creatBiTree(T->rchild);
	}
	return true;
}
bool PreOrderTraverse(BiTree T)
	//先序递归遍历二叉树
{
	if(T)
	{
		cout<<T->data;
		if(PreOrderTraverse(T->lchid))
			if(PreOrderTraverse(T->rchild))
				return true;
		return false;
	}
	else
		return true;
}
bool InOrderTraverse(BiTree T)
	//中序递归遍历二叉树
{
	if(T)
	{
		InOrderTraverse(T->lchid);
		cout<<T->data;
		InOrderTraverse(T->rchild);
		return true;
	}
	else
		return false;
}
bool PostOrderTraverse(BiTree T)
	//后序递归遍历二叉树
{
	if(T)
	{
		PostOrderTraverse(T->lchid);
		PostOrderTraverse(T->rchild);
		cout<<T->data;
	}
	else
		return false;
}
void RePreOrderTraverse(BiTree T)
	//先序非递归遍历二叉树
{
	SqStackPr S=new SqStack;
	S->Stop=0;
	BiTree p=T;
	while(p||S->Stop>0)
	{
		if(p)
		{
			cout<<p->data;
			S->Sdata[(S->Stop)++]=p;
			p=p->lchid;
		}
		else
		{
			p=S->Sdata[--(S->Stop)]->rchild;
		}
	}
}
void ReInOrderTraverse(BiTree T)
	//中序非递归遍历二叉树
{
	SqStackPr S=new SqStack;
	S->Stop=0;
	BiTree p=T;
	while(p||S->Stop>0)
	{
		if(p)
		{
			S->Sdata[(S->Stop)++]=p;
			p=p->lchid;
		}
		else
		{
			p=S->Sdata[--(S->Stop)];
			cout<<p->data;
			p=p->rchild;
		}
	}
}
void RePostOrderTraverse(BiTree T)
	//后序非递归遍历二叉树
{
	SqStackPr S=new SqStack;
	S->Stop=-1;
	BiTree p=T;
	while(p!=NULL||S->Stop!=-1)
	{
		while(p)
		{
			S->Sflag[++(S->Stop)]=0;
			S->Sdata[S->Stop]=p;
			p=p->lchid;
		}
		while(S->Stop>=0&&S->Sflag[S->Stop]==1)
		{
			p=S->Sdata[S->Stop];
			cout<<p->data;
			S->Stop--;
		}
		if(S->Stop>=0)
		{
			p=S->Sdata[S->Stop];
			S->Sflag[S->Stop]=1;
			p=p->rchild;
		}
		else
			p=NULL;
	}
}
void LevelOrderTraverse(BiTree T)
	//按层次遍历二叉树
{
	QueuePtr Q=new QNode;
	Q->Qdata[0]=T;
	Q->front=0;
	Q->rear=1;
	while(Q->front<Q->rear)
	{
		if(Q->Qdata[Q->front])
		{
			cout<<(Q->Qdata[Q->front])->data;
			Q->Qdata[(Q->rear)++]=(Q->Qdata[Q->front])->lchid;
			Q->Qdata[(Q->rear)++]=(Q->Qdata[Q->front])->rchild;
			Q->front++;
		}
		else
			Q->front++;
	}
}
int countLeafNode(BiTree T)
	//返回T二叉树的叶子节点个数
{
	BiTree p=T;
	if(p)
	{
		if(p->lchid==NULL&&p->rchild==NULL)
			return 1;
		else
			return countLeafNode(p->lchid)+countLeafNode(p->rchild);
	}
	return 0;
}
void outLeafNode(BiTree T)
	//输出所有叶子节点
{
	BiTree p=T;
	if(p)
	{
		if(p->lchid==NULL&&p->rchild==NULL)
		{
			cout<<p->data<<ends;
		}
		else
		{
			outLeafNode(p->lchid);
			outLeafNode(p->rchild);
		}
	}
}
int HeightOfTree(BiTree T)
	//返回T二叉树的高度
{
	BiTree p=T;
	if(p)
	{
		if(HeightOfTree(p->lchid)<HeightOfTree(p->rchild))
			return HeightOfTree(p->rchild)+1;
		else
			return HeightOfTree(p->lchid)+1;
	}
	else
		return 0;
}

int main()
{
	BiTree T=new BiTNode;
	cout<<"\n____________________________________二叉树____________________________________"
		<<"\n			1.创建一棵新的二叉树"
		<<"\n			2.先序，中序，后序遍历"
		<<"\n			3.计算叶子节点及个数"
		<<"\n			4.计算树的高度"
		<<"\n选择你要执行的功能操作：";
	int which_way;
	cin>>which_way;
	switch(which_way)
	{
	case 1:
		cout<<"\n*****************************************************************************";
		cout<<"\n请输入您创建的二叉树的节点值（空树用“#”表示）：\n";
		creatBiTree(T);
	case 2:
		cout<<"\n先序递归遍历二叉树：";
		PreOrderTraverse(T);
		cout<<"\n中序递归遍历二叉树：";
		InOrderTraverse(T);
		cout<<"\n后序递归遍历二叉树：";
		PostOrderTraverse(T);
		cout<<"\n\n先序非递归遍历二叉树：";
		RePreOrderTraverse(T);
		cout<<"\n中序非递归遍历二叉树：";
		ReInOrderTraverse(T);
		cout<<"\n后序非递归遍历二叉树：";
		RePostOrderTraverse(T);
		cout<<"\n\n按层次遍历二叉树：";
		LevelOrderTraverse(T);
	case 3:
		cout<<"\n\n此二叉树的叶子结点个数为："<<countLeafNode(T)
			<<"，所有叶子节点为：";
		outLeafNode(T);
	case 4:
		cout<<"\n\n该二叉树的高度为："<<HeightOfTree(T);
		break;
	}
	cout<<endl<<endl;
	/*system("pause");*/
	return 0;
}
