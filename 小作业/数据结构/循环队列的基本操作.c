/*����ֻ�����򣬶������Ž����ݽṹ���������ڻ���������Ͷ��У�����ջ���е��ǣ��������Ķ�ѭ�����е���Ҫ���������ܽᡣע��Ϊ�˱�����пպ�������״̬������
���ÿ���һ��λ�õķ�ʽ����N��Ԫ�ؿռ��ѭ���������ֻ�ܴ��N-1����ЧԪ�ء���Ҳ�Ǵ�����̲ĵ�������
1) ѭ�����г�ʼ����front=rear=0��
2����Ӳ�����rear=(rear+1)%size;
3�����Ӳ�����front=(front+1)%size;
4���ж��Ƿ�Ϊ�ն��У�front==rear��
5���ж϶����Ƿ�������front=(rear+1)%size��
6���������и�Ԫ�ء�*/



 #include <stdio.h>
 #include <stdlib.h>
 #include <malloc.h>
 #include <stdbool.h>   //ע��ʹ�ò�������ʱ����Ҫ�����ͷ�ļ�

 /*******************************************************************************************************************
 ����ѭ�����еĽṹ�塣ע��ѭ��������������Ļ�����ʵ�ֵģ�������Ҫһ��ָ����Ԫ�ص�ָ�룬����ͷ��β��int����ʾ���ƫ�������ɡ�
 ********************************************************************************************************************/
 typedef struct Queue
 {
     int * qBase;
     int front;
     int rear;
 }QUEUE;

 void initQueue(QUEUE *pq);
 void enQueue(QUEUE *pq , int value);
 bool isemptyQueue(QUEUE *pq);
 bool is_fullQueue(QUEUE *pq);
 void deQueue(QUEUE *pq , int *value);
 void traverseQueue( QUEUE *pq);

 /***************************************** ������������� ********************************************/
 int main(){
     int val;
     QUEUE queue = {NULL,0,0} ;
     initQueue(&queue);
     enQueue(&queue,4);
     enQueue(&queue,5);
     enQueue(&queue,6);
     enQueue(&queue,7);
     enQueue(&queue,72);
     enQueue(&queue,42);

     traverseQueue(&queue);
     deQueue(&queue , &val);
     deQueue(&queue , &val);

     traverseQueue(&queue);
     enQueue(&queue,55);
     enQueue(&queue,65);
     traverseQueue(&queue);

     return 0;
 }
 /**************************************��ʼ��һ���յ�ѭ������ ******************************************/
 void initQueue(QUEUE *pq){
     pq->qBase = (int *)malloc(sizeof(int)*6);
     if(pq->qBase == NULL){
         printf("�ڴ����ʧ�ܣ�\n");
         exit(-1);
     }
     pq->front = pq->rear = 0;
 }
 /***************����һ����Ԫ��  ע������ǰ��Ҫ���жϸö����Ƿ����������⸲����Ч����******************/

 void enQueue(QUEUE *pq , int value){

     if(is_fullQueue(pq)){
         printf("ѭ�������������ܾ�����%d��\n",value);
      }
��������else{
         pq->qBase[pq->rear] = value;
         pq->rear = (pq->rear + 1)%6 ;
         printf("\n %d ��� \n" , value);
      }
 }

 /**************  ɾ��һ��Ԫ��,��ͨ��ָ�뷵�ظ���  ע:ɾ��ǰҪ�жϸö����Ƿ�Ϊ�ա�*******************/

  void deQueue(QUEUE *pq , int *value){
      if(isemptyQueue(pq)){
����      printf("ѭ�������ѿգ�");
     }
������else{
         *value = pq->qBase[pq->front];
         printf("\n %d ���� \n",*value);
         pq->front = (pq->front + 1)%6 ;
      }
   }
  /************************************     �ж�ѭ�������Ƿ�Ϊ�� ************************************/
 bool isemptyQueue(QUEUE *pq){
     if(pq->front == pq->rear){
         return true;
     }
     else
         return false;
 }

 /************************************    �ж�ѭ�������Ƿ����� ************************************/
 bool is_fullQueue(QUEUE *pq){
     if((pq->rear +1)%6 == pq->front){
         return true;
     }else
         return false;
 }

 /*************************************     ����ѭ�������еĸ�Ԫ�� *************************************/
 void traverseQueue( QUEUE *pq){
     if(isemptyQueue(pq)){
         printf("ѭ������Ϊ��!\n");
         exit(0);
     }
     printf("��ǰѭ������ :\n");
     printf("front��%d,rear��%d :\n",pq->front,pq->rear);

     int tail = pq->front ;
     while(tail != pq->rear){
         printf(" %d ",pq->qBase[tail]);
         tail = (tail + 1)%6;
     }
 }


/*1�� ���ݽṹ
#define MAXQUEUE 100
struct SqQueue
{
       int *base;
       int front;
       int rear;
};
2������һ���ն���
void CreateQueue(struct SqQueue &Q)
{
       Q.base = (int *)malloc(MAXQUEUE * sizeof(int));
       if (Q.base == NULL)
       {
              exit(0);
       }
       Q.front = Q.rear = 0;
}
3�����ٶ���
void DestroyQueue(struct SqQueue &Q)
{
       if (Q.base != NULL)
       {
              free(Q.base);
              Q.base = NULL;
              Q.front = Q.rear = 0;
       }
}
4����ն���
void ClearQueue(struct SqQueue &Q)
{
       Q.front = Q.rear = 0;
}
5���ж϶����Ƿ�Ϊ��
bool EmptyQueue(struct SqQueue Q)
{
       if (Q.front == Q.rear)
       {
              return true;
       }
       else
       {
              return false;
       }
}
6������г���
int LengthQueue(struct SqQueue Q)
{
       int length = 0;
       length = (Q.rear - Q.front + MAXQUEUE) % MAXQUEUE;
       return length;
}
7�����в��գ��򷵻ض�ͷ
void GetQueueHead(struct SqQueue Q, int &value)
{
       if (!EmptyQueue(Q))
       {
              value = Q.base[Q.front];
       }
}
8�����в��գ���ɾ����ͷ
void DelQueueHead(struct SqQueue &Q, int &value)
{
       if (!EmptyQueue(Q))
       {
              value = Q.base[Q.front];
              Q.front = (Q.front+1)%MAXQUEUE;
       }
}
9������Ԫ�ص�����
void InsertQueue(struct SqQueue &Q, int value)
{
       if ((Q.rear + 1) % MAXQUEUE == Q.front)
       {
              printf("��������\n");
              return;
       }
       Q.base[Q.rear] = value;
       Q.rear = (Q.rear + 1) % MAXQUEUE;
}
10����������Ԫ��
void TraverseQueue(struct SqQueue Q)
{
       if (!EmptyQueue(Q))
       {
              int i = Q.front;
              while (i != Q.rear)
              {
                     printf("%d ", Q.base[i]);
                     i = (i+1) % MAXQUEUE;
              }
              printf("\n");
       }
}
*/
