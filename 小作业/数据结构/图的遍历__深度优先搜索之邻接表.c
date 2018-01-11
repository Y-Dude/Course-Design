#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE_ADJ 100
typedef int EdgeType;
typedef char VertexType;

///�����ڽӱ� �ڵ�����
typedef struct EdgeNode{
    int adjvex;     ///�ڽӵ����
    EdgeType weight;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode{
    VertexType data;    ///�����Ӧ������Ϣ
    EdgeType *firstEdge;    ///�ڽ������ͷ�ڽ���ַ��Ϣ
}VertexNode;

typedef struct ADJList{
    VertexNode vexs[MAXSIZE_ADJ];
    int numVex;
}ADJList;



///��ʼ��ͼ�ṹ
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
        ///���ڽӱ��в���ߣ���Ҫ����ͷ�巨
        newEdge->next=G->vexs[edges[i][0]].firstEdge;
        G->vexs[edges[i][0]].firstEdge=newEdge;
    }
}

///�ͷ��ڽӱ��У����ж�̬����ռ�
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

///�Զ���Ԫ��d���ʲ������������Ԫ��ֵ
void Visit_ADJ(VertexType e){
    printf("%d ",e);
}

void DFS_Traverse_ADJ(ADJList G, int i, int *tag){
    int j;
    EdgeNode *p;
    if(tag[i]) return ;
    Visit_ADJ(G.vexs[i].data);
    tag[i]=1;
    ///�ڶ���i�������ڽӵ��У�ѡ��һ��δ���ʹ����ڽӵ㣬������һ���DFS
    for(p=G.vexs[i].firstEdge;p!=NULL;p=p->next)
        if(!tag[p->adjvex])
            DFS_Traverse_ADJ(G,p->adjvex,tag);
}


///��ͼ�ṹ����������ȱ���
void DFS_ADJ(ADJList G){
    ///����һ���������Ŀռ䣬��ʼֵȫ��Ϊ0�������ʶ���֮�󣬱��Ϊ1
    int i,*tag=(int *)malloc(sizeof(int)*(G.numVex+1));
    memset(tag,0,sizeof(int)*(G.numVex+1));
    /*for(i=1;i<=G.numVex+1;i++)
        tag[i]=0;*/
        ///ͨ��ѭ��ѡ��DFS��㣬����Ϊ�п���Ϊ����ͨͼ��һ��DFS�޷�����ȫ��
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
