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



///求取指定序号顶点的度数之和（入读和出度）
int GetDegree_AM(AMatrix G, int i){
    ///顶点对应的邻接矩阵的行数据，改行不为零且不为无穷的数的个数，即为度
    int count=0;
    int j;
    if(i<0&&i>=G.numVex)
        return -1;  ///表示该顶点序号不合法
    for(j=0;j<G.numVex;j++){
        if(G.edges[i][j]!=0&&G.edges[i][j]!=MAXVALUE_AM)
            count++;
    }
    return count;
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
        for(i=0;i<G.numVex;i++){
            printf("第%d个顶点的度数为%d\n",(i+1),GetDegree_AM(G,i));
        }
    }
}
