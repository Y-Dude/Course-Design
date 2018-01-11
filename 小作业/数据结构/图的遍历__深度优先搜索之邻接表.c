#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
        G->vexs[i].data =i;
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

void DFS_Traverse_ADJ(ADJList G, int i, int *tag){
    int j;
    EdgeNode *p;
    if(tag[i]) return ;
    Visit_ADJ(G.vexs[i].data);
    tag[i]=1;
    ///在顶点i的所有邻接点中，选择一个未访问过的邻接点，进入下一层的DFS
    for(p=G.vexs[i].firstEdge;p!=NULL;p=p->next)
        if(!tag[p->adjvex])
            DFS_Traverse_ADJ(G,p->adjvex,tag);
}


///对图结构进行深度优先遍历
void DFS_ADJ(ADJList G){
    ///申请一个标记数组的空间，初始值全置为0；当访问顶点之后，标记为1
    int i,*tag=(int *)malloc(sizeof(int)*(G.numVex+1));
    memset(tag,0,sizeof(int)*(G.numVex+1));
    /*for(i=1;i<=G.numVex+1;i++)
        tag[i]=0;*/
        ///通过循环选择DFS起点，是因为有可能为非连通图，一趟DFS无法遍历全部
    for(i=1;i<=G.numVex;i++)
        if(!tag[i])
            DFS_Traverse_ADJ(G,i,tag);
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
        DFS_ADJ(G);
        printf("\n");
        Destroy_ADJ(&G);
    }
}
