#include<stdio.h>
#define MAXSIZE_AM 100
#define MAXVALUE_AM 99999

typedef char VertexType;
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
        G->vexs[i]=('1'+i);  ///初始化顶点信息，默认为序号
        for(j=0;j<n;j++)        ///根据用户输入，初始化边的信息
        G->edges[i][j]=edges[i][j];
    }
}


///图的最小生成树Prim算法
///AMatrix G； 邻接矩阵存储结构的图
///int *adj ； 一个向量； 用于存储最小生成树中，权值边对应点端点（i，adj【i】）
///返回值，最小生成树中所有权值边的权值总和
int Minispantree_Prim(AMatrix G,int *adj){
     int *cost=(int *)malloc(sizeof(int)* G.numVex);
     int i,j,minicost,miniindex,totalcost=0;
     cost[0]=0;adj[0]=0;
     for(i=1;i<G.numVex;i++)
     {
         cost[i]=G.edges[0][i];
         adj[i]=0;
     }
     for(i=0;i<G.numVex-1;i++){
            minicost=MAXVALUE_AM;
        for(j=0;j<G.numVex;j++)
        {
            if(cost[j]){
                if(cost[j]<minicost){ minicost=cost[j]; miniindex=j;}
            }
        }
        totalcost+=minicost;
     cost[miniindex]=0;
     for(j=0;j<G.numVex;j++){
        if(cost[j]!=0){
            if(cost[j]>G.edges[miniindex][j]){
                cost[j]=G.edges[miniindex][j];
                adj[j]=miniindex;
            }
        }
     }
     }
     free(cost);
     return totalcost;
}



int main(){
    int n,i,j;
    int edges[MAXSIZE_AM][MAXSIZE_AM];
    AMatrix G;
    int cost;
    int adj[MAXSIZE_AM];
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
            scanf("%d",&edges[i][j]);
            if(i!=j&&edges[i][j]==0){
                edges[i][j]=MAXVALUE_AM;
            }
            }
        Init_AM(&G,n,edges);
        cost=Minispantree_Prim(G,adj);
        printf("%d\n",cost);
       printf("生成树的边为：");
        for(i=0;i<G.numVex;i++)
            printf("<%d,%d>",i,adj[i]);
        printf("\n");
    }
}
