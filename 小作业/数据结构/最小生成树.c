#include<stdio.h>
#define MAXSIZE_AM 100
#define MAXVALUE_AM 99999

typedef char VertexType;
typedef int EdgeType;


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


///ͼ����С������Prim�㷨
///AMatrix G�� �ڽӾ���洢�ṹ��ͼ
///int *adj �� һ�������� ���ڴ洢��С�������У�Ȩֵ�߶�Ӧ��˵㣨i��adj��i����
///����ֵ����С������������Ȩֵ�ߵ�Ȩֵ�ܺ�
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
       printf("�������ı�Ϊ��");
        for(i=0;i<G.numVex;i++)
            printf("<%d,%d>",i,adj[i]);
        printf("\n");
    }
}
