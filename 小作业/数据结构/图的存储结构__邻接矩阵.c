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



///��ȡָ����Ŷ���Ķ���֮�ͣ�����ͳ��ȣ�
int GetDegree_AM(AMatrix G, int i){
    ///�����Ӧ���ڽӾ���������ݣ����в�Ϊ���Ҳ�Ϊ��������ĸ�������Ϊ��
    int count=0;
    int j;
    if(i<0&&i>=G.numVex)
        return -1;  ///��ʾ�ö�����Ų��Ϸ�
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
            printf("��%d������Ķ���Ϊ%d\n",(i+1),GetDegree_AM(G,i));
        }
    }
}
