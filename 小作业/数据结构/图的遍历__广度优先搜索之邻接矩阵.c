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


///图的邻接矩阵表示
typedef struct AMatrix{
    VertexType vexs[MAXSIZE_AM];      ///存储顶点信息的一维数组
    EdgeType edges[MAXSIZE_AM][MAXSIZE_AM];     ///存储边或弧信息的二维数组，即邻接矩阵
    int numVex;     ///图中顶点个数
}AMatrix;



///根据用户输入，创建邻接矩阵描述图
void Init_AM(AMatrix *G, int n,int  edges[MAXSIZE_AM][MAXSIZE_AM]){
    int i,j;
    G->numVex=n;
    for(i=0;i<n;i++){
        G->vexs[i]=('1'+i);  ///初始化顶点信息，默认为序号
        for(j=0;j<n;j++)        ///根据用户输入，初始化边的信息
        G->edges[i][j]=edges[i][j];
    }
}

///对顶点元素的访问操作，比如输出元素值
void Visit_AM(VertexType e){
    printf("%d ",e);
}


///对图结构，进行广度优先遍历
void BFS_AM(AMatrix G){
    ///申请一个标记顶点是否被访问过或曾经入队过（避免重复入队）
    int i,j,*tag=(int *)malloc(sizeof(int)*G.numVex);
    CQueue Q;
    Init_CQ(&Q);
    memset(tag,0,sizeof(int)*G.numVex);
    ///任意选择一个起点，将其入队，开始广度遍历
    for(i=0;i<G.numVex;i++){
        if(!tag[i]){
        EnCQueue(&Q,i);
        tag[i]=1;
        }
    ///广度遍历
    ///1.从队列中取出顶点将其所有未被访问过的邻接点入队
    ///2.如果队列空类了，则当次的广度遍历结束
        while(!CQueueEmpty(&Q)){
        DeCQueue(&Q,&i);
        Visit_AM(G.vexs[i]);
        for(j=0;j<G.numVex;j++){
            if(G.edges[i][j]!=0&&G.edges[i][j]!=MAXVALUE_AM)
            if(!tag[j]){            ///入队即将其标记，然后进行访问
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
