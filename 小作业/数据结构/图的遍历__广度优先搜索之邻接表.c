#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE_ADJ 100
#define MAXSIZE_CQ 1000
typedef int DataType;
typedef int EdgeType;
typedef char VertexType;

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

int CQueueEmpty(CQueue *Q)
{
       if (Q->front == Q->rear)
       {
              return 1;
       }
       else
       {
              return 0;
       }
}


///定义邻接表 节点类型
typedef struct EdgeNode{
    int adjvex;     ///邻接点序号
    EdgeType weight;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode{
    VertexType data;    ///顶点对应数据信息
    EdgeType *firstEdge;    ///邻接链表的头节结点地址信息
}VertexNode;

typedef struct ADJList{
    VertexNode vexs[MAXSIZE_ADJ];
    int numVex;
}ADJList;



///初始化图结构
void Init_ADJ(ADJList *G, int n, int edges[1000][2], int edgeNum){
    int i;
    EdgeNode *newEdge;
    G->numVex=n;
    for(i=1;i<=n;i++){
        G->vexs[i].data =i+1;
        G->vexs[i].firstEdge=NULL;
    }
    for(i=0;i<edgeNum;i++){
        newEdge=(EdgeNode *)malloc(sizeof(EdgeNode));
        newEdge->adjvex=edges[i][1];
        ///在邻接表中插入边，需要采用头插法
        newEdge->next=G->vexs[edges[i][0]].firstEdge;
        G->vexs[edges[i][0]].firstEdge=newEdge;
    }
}

///释放邻接表中，所有动态申请空间
void Destroy_ADJ(ADJList *G){
    int i;
    EdgeNode *p,*q;
    for(i=1;i<=G->numVex;i++){
        p=G->vexs[i].firstEdge;
        while(p){
            q=p->next;
            free(p);
            p=q;
        }
    }
}

///对顶点元素d访问操作，比如输出元素值
void Visit_ADJ(VertexType e){
    printf("%d ",e);
}


///对图结构，进行广度优先遍历
void BFS_ADJ(ADJList G){
    ///申请一个标记顶点是否被访问过或曾经入队过（避免重复入队）
    int i,j;
    int *tag=(int *)malloc(sizeof(int)*(G.numVex+1));
    EdgeNode *p;
    CQueue Q;
    Init_CQ(&Q);
    memset(tag,0,sizeof(int)*(G.numVex+1));
    ///任意选择一个起点，将其入队，开始广度遍历
    for(i=1;i<=G.numVex;i++){
        if(!tag[i]){
        EnCQueue(&Q,i);
        tag[i]=1;
        }
    ///广度遍历
    ///1.从队列中取出顶点将其所有未被访问过的邻接点入队
    ///2.如果队列空类了，则当次的广度遍历结束
        while(!CQueueEmpty(&Q)){
        DeCQueue(&Q,&j);
        Visit_ADJ(G.vexs[j].data);
        ///邻接矩阵与邻接表差别在于，对邻接点关系的存储方式不同
        for(p=G.vexs[j].firstEdge;p!=NULL;p=p->next){
            if(!tag[p->adjvex]){
                EnCQueue(&Q,p->adjvex);
                tag[p->adjvex]=1;
            }
        }
    }
    }
    free(tag);
}


int main(){
    int n,m,i;
    int edges[1000][2];
    ADJList G;
    while(scanf("%d %d",&n,&m)!=EOF){
            if(n==0&&m==0)
            break;
        for(i=0;i<m;i++)
            scanf("%d %d",&edges[i][0],&edges[i][1]);
        Init_ADJ(&G,n,edges,m);
        BFS_ADJ(G);
        printf("\n");
        Destroy_ADJ(&G);
    }
}

