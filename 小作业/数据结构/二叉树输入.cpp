#include <iostream>
using namespace std;
#define STACK_INIT_SIZE 100
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchid, *rchild;
}BiTNode, *BiTree;				        //�������ṹ��
typedef struct
{
	BiTNode *Sdata[STACK_INIT_SIZE];	//�������ڵ��Ŵ�
	int Sflag[STACK_INIT_SIZE];		    //��¼Stop���Ƿ��ж������ڵ�
	int Stop;						    //Sdataλ�Ƽ�¼��
}SqStack, *SqStackPr;
typedef struct
{
	BiTNode *Qdata[STACK_INIT_SIZE];
	int front;
	int rear;
}QNode, *QueuePtr;
bool creatBiTree(BiTree &T)
	//�������������������еĽڵ�ֵ
{
	char _data;
	cin>>_data;
	BiTree p=T;					        //��¼T��ǰ��ָ�ڵ�
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
			cout<<"\n�ڴ�ռ䲻�㣬�������ڵ㴴��ʧ�ܣ�";
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
	//����ݹ����������
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
	//����ݹ����������
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
	//����ݹ����������
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
	//����ǵݹ����������
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
	//����ǵݹ����������
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
	//����ǵݹ����������
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
	//����α���������
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
	//����T��������Ҷ�ӽڵ����
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
	//�������Ҷ�ӽڵ�
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
	//����T�������ĸ߶�
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
	cout<<"\n____________________________________������____________________________________"
		<<"\n			1.����һ���µĶ�����"
		<<"\n			2.�������򣬺������"
		<<"\n			3.����Ҷ�ӽڵ㼰����"
		<<"\n			4.�������ĸ߶�"
		<<"\nѡ����Ҫִ�еĹ��ܲ�����";
	int which_way;
	cin>>which_way;
	switch(which_way)
	{
	case 1:
		cout<<"\n*****************************************************************************";
		cout<<"\n�������������Ķ������Ľڵ�ֵ�������á�#����ʾ����\n";
		creatBiTree(T);
	case 2:
		cout<<"\n����ݹ������������";
		PreOrderTraverse(T);
		cout<<"\n����ݹ������������";
		InOrderTraverse(T);
		cout<<"\n����ݹ������������";
		PostOrderTraverse(T);
		cout<<"\n\n����ǵݹ������������";
		RePreOrderTraverse(T);
		cout<<"\n����ǵݹ������������";
		ReInOrderTraverse(T);
		cout<<"\n����ǵݹ������������";
		RePostOrderTraverse(T);
		cout<<"\n\n����α�����������";
		LevelOrderTraverse(T);
	case 3:
		cout<<"\n\n�˶�������Ҷ�ӽ�����Ϊ��"<<countLeafNode(T)
			<<"������Ҷ�ӽڵ�Ϊ��";
		outLeafNode(T);
	case 4:
		cout<<"\n\n�ö������ĸ߶�Ϊ��"<<HeightOfTree(T);
		break;
	}
	cout<<endl<<endl;
	/*system("pause");*/
	return 0;
}
