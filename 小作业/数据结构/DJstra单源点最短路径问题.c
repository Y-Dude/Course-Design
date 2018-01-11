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



///图的最短路径问题（单源点）：Dijistra算法
///参数 shortest ：源点到对应序号顶点的最短路径长度
///参数path 源点到 对应序号顶点的最短路径，最后一步所中转的顶点序号
void  Dijistra(AMatrix G,int v0, int *shortest, int *path){
    ///初始化辅助向量u，表示源点到对应序号顶点的最短路径是否求出：0-为求出，1-已求出
    int *u=(int *)malloc(sizeof(int)*G.numVex);
    int i,j,k,minilen,miniindex;
    for(i=0;i<G.numVex;i++){
        shortest[i]=G.edges[v0][i];
        u[i]=0;
        path[i]=v0;
    }
    u[v0]=1;
    ///重复 n-1次
    ///根据 shortest 向量，求出V—U中当前最短路径
    ///将选中的路径，加入U中
    ///根据新加入的路径，更新V-U中的最短路径
    for(i=0;i<G.numVex-1;i++){
            minilen=MAXVALUE_AM;
        for(j=0;j<G.numVex;j++){         ///根据 shortest 向量，求出V—U中当前最短路径
            if(!u[j]&&shortest[j]<minilen){
                minilen=shortest[j];
                miniindex=j;
            }
        }
        u[miniindex]=1;  ///把选中路径加入U中

        for(j=0;j<G.numVex;j++){           ///根据新加入的路径，更新V-U中的最短路径
            if(!u[j]&&shortest[j]>shortest[miniindex]+G.edges[miniindex][j]){
                shortest[j]=shortest[miniindex]+G.edges[miniindex][j];
                path[j]=miniindex;
            }
        }
    }
    free(u);
}




int main(){
    int n,i,j,v0;
    int edges[MAXSIZE_AM][MAXSIZE_AM];
    int shortest[MAXSIZE_AM],path[MAXSIZE_AM];
    AMatrix G;
    int stack[MAXSIZE_AM],top;
    while(scanf("%d %d",&n,&v0)!=EOF){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
            scanf("%d",&edges[i][j]);
            if(i!=j&&edges[i][j]==0)
                edges[i][j]=MAXVALUE_AM;
                }
        Init_AM(&G,n,edges);

        Dijistra(G,v0,shortest,path);
        for(i=0;i<G.numVex;i++){
            if(i==v0) continue;
            printf("顶点 %d 到顶点 %d 的最短路径长度为：%d",v0,i,shortest[i]);
            printf("短路径为：");
            ///0->path[i]->i
            top=-1;
            j=i;
            while(j!=v0){
                stack[++top]=j;
                j=path[j];
            }
            printf("%d",v0);
            while(top!=-1)
                printf("->%d ",stack[top--]);
                printf("\n");
        }
        }
}
