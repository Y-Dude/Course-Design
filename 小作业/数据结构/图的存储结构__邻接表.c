#include<stdio.h>
#include<stdlib.h>
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

typedef struct ADJList{     ///ͼ���ڽӱ��ʾ����
    VertexNode vexs[MAXSIZE_ADJ];    ///�����㼯��
    int numVex;         ///�������
}ADJList;



///��ʼ��ͼ�ṹ
void Init_ADJ(ADJList *G, int n, int edges[1000][2], int edgeNum){
    int i;
    EdgeNode *newEdge;
    G->numVex=n;
    for(i=1;i<=n;i++){      ///��ʼ������N��������ڽӱ�
        G->vexs[i].data =i+1;
        G->vexs[i].firstEdge=NULL;  ///ע��ָ���ÿ�
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

///��ָ����Ž��ĳ���
int GetDegree_ADJ(ADJList G,int i){
    ///�˴� i ��1��ʼ
    EdgeNode *p;
    int count=0;
    if(i<1||i>G.numVex)
        return -1;
    p=G.vexs[i].firstEdge;
    while(p){   ///ͨ��һ��ָ�룬�����ڽ�����������ĳ���
    count++;
    p=p->next;
    }///�ڽ�����ĳ��ȣ���Ϊ�ö���ĳ���
    return count;
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
            for(i=1;i<=G.numVex;i++)
                printf("��%d������ĳ�����%d\n",i,GetDegree_ADJ(G,i));
            Destroy_ADJ(&G);
    }
    return 0;
}
