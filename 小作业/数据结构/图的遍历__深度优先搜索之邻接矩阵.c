#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE_AM 100
#define MAXVALUE_AM 99999

typedef int VertexType;
typedef int EdgeType;



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
        G->vexs[i]=(i);  ///初始化顶点信息，默认为序号
        for(j=0;j<n;j++)        ///根据用户输入，初始化边的信息
        G->edges[i][j]=edges[i][j];
    }
}


///对顶点元素d访问操作，比如输出元素值
void Visit_AM(VertexType e){
    printf("%d ",e);
}

void DFS_Traverse_AM(AMatrix G, int i, int *tag){
    int j;
    if(tag[i]) return ;
    Visit_AM(G.vexs[i]);
    tag[i]=1;
    ///在顶点i的所有邻接点中，选择一个未访问过的邻接点，进入下一层的DFS
    for(j=0;j<G.numVex;j++){        ///通过遍历邻接矩阵中第i 行来查找顶点i的邻接点
        if(G.edges[i][j]!=0&&G.edges[i][j]!=MAXVALUE_AM)
            if(!tag[j])     ///一定要有否则会死循环
            DFS_Traverse_AM(G,j,tag);
    }
}


///对图结构进行深度优先遍历
void DFS_AM(AMatrix G){
    ///申请一个标记数组的空间，初始值全置为0；当访问顶点之后，标记为1
    int i,*tag=(int *)malloc(sizeof(int)*G.numVex);
    memset(tag,0,sizeof(int)*G.numVex);
    /*可写为 for(i=0;i<G.numVex;i++)
        tag[i]=0;*/
        ///通过循环选择DFS起点，是因为有可能为非连通图，一趟DFS无法遍历全部
    for(i=0;i<G.numVex;i++)
        if(!tag[i])
            DFS_Traverse_AM(G,i,tag);

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
        DFS_AM(G);
        printf("\n");
    }
}
