#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE_AM 100
#define MAXVALUE_AM 99999

typedef int VertexType;
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
        G->vexs[i]=(i);  ///��ʼ��������Ϣ��Ĭ��Ϊ���
        for(j=0;j<n;j++)        ///�����û����룬��ʼ���ߵ���Ϣ
        G->edges[i][j]=edges[i][j];
    }
}


///�Զ���Ԫ��d���ʲ������������Ԫ��ֵ
void Visit_AM(VertexType e){
    printf("%d ",e);
}

void DFS_Traverse_AM(AMatrix G, int i, int *tag){
    int j;
    if(tag[i]) return ;
    Visit_AM(G.vexs[i]);
    tag[i]=1;
    ///�ڶ���i�������ڽӵ��У�ѡ��һ��δ���ʹ����ڽӵ㣬������һ���DFS
    for(j=0;j<G.numVex;j++){        ///ͨ�������ڽӾ����е�i �������Ҷ���i���ڽӵ�
        if(G.edges[i][j]!=0&&G.edges[i][j]!=MAXVALUE_AM)
            if(!tag[j])     ///һ��Ҫ�з������ѭ��
            DFS_Traverse_AM(G,j,tag);
    }
}


///��ͼ�ṹ����������ȱ���
void DFS_AM(AMatrix G){
    ///����һ���������Ŀռ䣬��ʼֵȫ��Ϊ0�������ʶ���֮�󣬱��Ϊ1
    int i,*tag=(int *)malloc(sizeof(int)*G.numVex);
    memset(tag,0,sizeof(int)*G.numVex);
    /*��дΪ for(i=0;i<G.numVex;i++)
        tag[i]=0;*/
        ///ͨ��ѭ��ѡ��DFS��㣬����Ϊ�п���Ϊ����ͨͼ��һ��DFS�޷�����ȫ��
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
