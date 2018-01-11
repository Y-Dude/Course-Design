#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAXSIZE_AM 100
#define MAXVALUE_AM 99999
#define MAXSIZE_CQ 1000

typedef int DataType;
typedef char VertexType;
typedef int EdgeType;


typedef struct CQueue{
    DataType *base;      /*space[MAXSIZE_CQ];*/
    int front,rear;
}CQueue;

void Init_CQ(CQueue *Q){
     Q->base=(DataType *)malloc(MAXSIZE_CQ * sizeof(DataType));
     if(!Q->base) exit(0);
     Q->front=Q->rear=0;
}


void EnCQueue(CQueue *Q, DataType e){
    scanf("%d",&e);
    if((Q->rear+1)%MAXSIZE_CQ==Q->front)
        {printf("sorry The Queue is full!/nNOW The Program will be out!/n");exit(0);}
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE_CQ;
}


void DeCQueue(CQueue *Q, DataType *e){
     if(Q->front==Q->rear)
        {printf("Sorry the queue is empty/nNOW The Program will be out!/n");exit(0);}
    e=Q->base[Q->front];
    Q->front=(Q->front+1)%MAXSIZE_CQ;
}


bool CQueueEmpty(CQueue *Q)
{
       if (Q->front == Q->rear)
       {
              return true;
       }
       else
       {
              return false;
       }
}


///ͼ���ڽӾ����ʾ
typedef struct AMatrix{
    VertexType vexs[MAXSIZE_AM];      ///�洢������Ϣ��һά����
    EdgeType edges[MAXSIZE_AM][MAXSIZE_AM];     ///�洢�߻���Ϣ�Ķ�ά���飬���ڽӾ���
    int numVex;     ///ͼ�ж������
}AMatrix;



///�����û����룬�����ڽӾ�������ͼ
void Init_AM(AMatrix *G, int n,int  edges[MAXSIZE_AM][MAXSIZE_AM]){
    int i,j;
    G->numVex=n;
    for(i=0;i<n;i++){
        G->vexs[i]=('1'+i);  ///��ʼ��������Ϣ��Ĭ��Ϊ���
        for(j=0;j<n;j++)        ///�����û����룬��ʼ���ߵ���Ϣ
        G->edges[i][j]=edges[i][j];
    }
}

///�Զ���Ԫ�صķ��ʲ������������Ԫ��ֵ
void Visit_AM(VertexType e){
    printf("%d ",e);
}


///��ͼ�ṹ�����й�����ȱ���
void BFS_AM(AMatrix G){
    ///����һ����Ƕ����Ƿ񱻷��ʹ���������ӹ��������ظ���ӣ�
    int i,j,*tag=(int *)malloc(sizeof(int)*G.numVex);
    CQueue Q;
    Init_CQ(&Q);
    memset(tag,0,sizeof(int)*G.numVex);
    ///����ѡ��һ����㣬������ӣ���ʼ��ȱ���
    for(i=0;i<G.numVex;i++){
        if(!tag[i]){
        EnCQueue(&Q,i);
        tag[i]=1;
        }
    ///��ȱ���
    ///1.�Ӷ�����ȡ�����㽫������δ�����ʹ����ڽӵ����
    ///2.������п����ˣ��򵱴εĹ�ȱ�������
        while(!CQueueEmpty(&Q)){
        DeCQueue(&Q,&i);
        Visit_AM(G.vexs[i]);
        for(j=0;j<G.numVex;j++){
            if(G.edges[i][j]!=0&&G.edges[i][j]!=MAXVALUE_AM)
            if(!tag[j]){            ///��Ӽ������ǣ�Ȼ����з���
                EnCQueue(&Q,j);
                tag[j]=1;
            }
        }
    }
    }
    free(tag);
}

int main(){
    int n,i,j;
    int edges[MAXSIZE_AM][MAXSIZE_AM];
    AMatrix G;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            scanf("%d",&edges[i][j]);
        Init_AM(&G,n,edges);
        BFS_AM(G);
        printf("\n");
    }
}
