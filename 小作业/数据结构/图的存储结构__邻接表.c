#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE_ADJ 100
typedef int EdgeType;
typedef char VertexType;

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

typedef struct ADJList{     ///图的邻接表表示方法
    VertexNode vexs[MAXSIZE_ADJ];    ///顶点结点集合
    int numVex;         ///顶点个数
}ADJList;



///初始化图结构
void Init_ADJ(ADJList *G, int n, int edges[1000][2], int edgeNum){
    int i;
    EdgeNode *newEdge;
    G->numVex=n;
    for(i=1;i<=n;i++){      ///初始化具有N个顶点的邻接表
        G->vexs[i].data =i+1;
        G->vexs[i].firstEdge=NULL;  ///注意指针置空
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

///求指定序号结点的出度
int GetDegree_ADJ(ADJList G,int i){
    ///此处 i 从1开始
    EdgeNode *p;
    int count=0;
    if(i<1||i>G.numVex)
        return -1;
    p=G.vexs[i].firstEdge;
    while(p){   ///通过一个指针，遍历邻接链表，求链表的长度
    count++;
    p=p->next;
    }///邻接链表的长度，即为该顶点的出度
    return count;
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
            for(i=1;i<=G.numVex;i++)
                printf("第%d个顶点的出度是%d\n",i,GetDegree_ADJ(G,i));
            Destroy_ADJ(&G);
    }
    return 0;
}
