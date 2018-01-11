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


void Floyd(AMatrix G,int shortest[MAXSIZE_AM][MAXSIZE_AM],int path[MAXSIZE_AM][MAXSIZE_AM]){
    int i,j,k;
    for(i=0;i<G.numVex;i++){
        for(j=0;j<G.numVex;j++){
            shortest[i][j]=G.edges[i][j];
            path[i][j]=i;
        }
    }
    for(k=0;k<=G.numVex-1;k++){
        for(i=0;i<G.numVex;i++){
            for(j=0;j<G.numVex;j++){
                if(shortest[i][j]>shortest[i][k]+shortest[k][j]){
                    shortest[i][j]=shortest[i][k]+shortest[k][j];
                    path[i][j]=k;
                }
            }
        }
    }
}




int main(){
    int n,i,j,k;
    int edges[MAXSIZE_AM][MAXSIZE_AM],shortest[MAXSIZE_AM][MAXSIZE_AM],path[MAXSIZE_AM][MAXSIZE_AM];
    AMatrix G;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
            scanf("%d",&edges[i][j]);
            if(i!=j&&edges[i][j]==0)
                edges[i][j]=MAXVALUE_AM;
        }
        Init_AM(&G,n,edges);
        Floyd(G,shortest,path);
        for(i=0;i<G.numVex;i++){
        for(j=0;j<G.numVex;j++){
                if(i==j) continue;
            printf("%d->%d·�����ȣ�%d--- " ,i,j,shortest[i][j]);
            /*top=-1;
            k=j;
            while(k!=i){
                stack[++top]=k;
                k=path[i][k];
            }
            printf("·��Ϊ��");
            while(top!=-1)
                printf("->%d",stack[top--]);*/
            printf("\n");
        }

        }
    }
}
