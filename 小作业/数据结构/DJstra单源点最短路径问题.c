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



///ͼ�����·�����⣨��Դ�㣩��Dijistra�㷨
///���� shortest ��Դ�㵽��Ӧ��Ŷ�������·������
///����path Դ�㵽 ��Ӧ��Ŷ�������·�������һ������ת�Ķ������
void  Dijistra(AMatrix G,int v0, int *shortest, int *path){
    ///��ʼ����������u����ʾԴ�㵽��Ӧ��Ŷ�������·���Ƿ������0-Ϊ�����1-�����
    int *u=(int *)malloc(sizeof(int)*G.numVex);
    int i,j,k,minilen,miniindex;
    for(i=0;i<G.numVex;i++){
        shortest[i]=G.edges[v0][i];
        u[i]=0;
        path[i]=v0;
    }
    u[v0]=1;
    ///�ظ� n-1��
    ///���� shortest ���������V��U�е�ǰ���·��
    ///��ѡ�е�·��������U��
    ///�����¼����·��������V-U�е����·��
    for(i=0;i<G.numVex-1;i++){
            minilen=MAXVALUE_AM;
        for(j=0;j<G.numVex;j++){         ///���� shortest ���������V��U�е�ǰ���·��
            if(!u[j]&&shortest[j]<minilen){
                minilen=shortest[j];
                miniindex=j;
            }
        }
        u[miniindex]=1;  ///��ѡ��·������U��

        for(j=0;j<G.numVex;j++){           ///�����¼����·��������V-U�е����·��
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
            printf("���� %d ������ %d �����·������Ϊ��%d",v0,i,shortest[i]);
            printf("��·��Ϊ��");
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
