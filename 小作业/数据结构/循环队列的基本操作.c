/*不是只有排序，二叉树才叫数据结构，面试栽在基本的数组和队列，链表，栈的有的是！！！本文对循环队列的重要操作作出总结。注：为了避免队列空和满两个状态混淆，
采用空闲一个位置的方式，即N个元素空间的循环队列最多只能存放N-1个有效元素。这也是大多数教材的做法。
1) 循环队列初始化：front=rear=0；
2）入队操作：rear=(rear+1)%size;
3）出队操作：front=(front+1)%size;
4）判断是否为空队列：front==rear；
5）判断队列是否已满：front=(rear+1)%size；
6）遍历队列各元素。*/



 #include <stdio.h>
 #include <stdlib.h>
 #include <malloc.h>
 #include <stdbool.h>   //注意使用布尔类型时，需要引入此头文件

 /*******************************************************************************************************************
 定义循环队列的结构体。注：循环队列是在数组的基础上实现的，所以需要一个指向首元素的指针，另外头和尾用int来表示相对偏移量即可。
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

 /***************************************** 主函数测试入口 ********************************************/
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
 /**************************************初始化一个空的循环队列 ******************************************/
 void initQueue(QUEUE *pq){
     pq->qBase = (int *)malloc(sizeof(int)*6);
     if(pq->qBase == NULL){
         printf("内存分配失败！\n");
         exit(-1);
     }
     pq->front = pq->rear = 0;
 }
 /***************插入一个新元素  注：插入前需要先判断该队列是否已满，避免覆盖有效数据******************/

 void enQueue(QUEUE *pq , int value){

     if(is_fullQueue(pq)){
         printf("循环队列已满，拒绝插入%d！\n",value);
      }
　　　　else{
         pq->qBase[pq->rear] = value;
         pq->rear = (pq->rear + 1)%6 ;
         printf("\n %d 入队 \n" , value);
      }
 }

 /**************  删除一个元素,并通过指针返回该数  注:删除前要判断该队列是否为空。*******************/

  void deQueue(QUEUE *pq , int *value){
      if(isemptyQueue(pq)){
　　      printf("循环队列已空！");
     }
　　　else{
         *value = pq->qBase[pq->front];
         printf("\n %d 出队 \n",*value);
         pq->front = (pq->front + 1)%6 ;
      }
   }
  /************************************     判断循环队列是否为空 ************************************/
 bool isemptyQueue(QUEUE *pq){
     if(pq->front == pq->rear){
         return true;
     }
     else
         return false;
 }

 /************************************    判断循环队列是否已满 ************************************/
 bool is_fullQueue(QUEUE *pq){
     if((pq->rear +1)%6 == pq->front){
         return true;
     }else
         return false;
 }

 /*************************************     遍历循环队列中的各元素 *************************************/
 void traverseQueue( QUEUE *pq){
     if(isemptyQueue(pq)){
         printf("循环队列为空!\n");
         exit(0);
     }
     printf("当前循环队列 :\n");
     printf("front是%d,rear是%d :\n",pq->front,pq->rear);

     int tail = pq->front ;
     while(tail != pq->rear){
         printf(" %d ",pq->qBase[tail]);
         tail = (tail + 1)%6;
     }
 }


/*1、 数据结构
#define MAXQUEUE 100
struct SqQueue
{
       int *base;
       int front;
       int rear;
};
2、构造一个空队列
void CreateQueue(struct SqQueue &Q)
{
       Q.base = (int *)malloc(MAXQUEUE * sizeof(int));
       if (Q.base == NULL)
       {
              exit(0);
       }
       Q.front = Q.rear = 0;
}
3、销毁队列
void DestroyQueue(struct SqQueue &Q)
{
       if (Q.base != NULL)
       {
              free(Q.base);
              Q.base = NULL;
              Q.front = Q.rear = 0;
       }
}
4、清空队列
void ClearQueue(struct SqQueue &Q)
{
       Q.front = Q.rear = 0;
}
5、判断队列是否为空
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
6、求队列长度
int LengthQueue(struct SqQueue Q)
{
       int length = 0;
       length = (Q.rear - Q.front + MAXQUEUE) % MAXQUEUE;
       return length;
}
7、队列不空，则返回队头
void GetQueueHead(struct SqQueue Q, int &value)
{
       if (!EmptyQueue(Q))
       {
              value = Q.base[Q.front];
       }
}
8、队列不空，则删除队头
void DelQueueHead(struct SqQueue &Q, int &value)
{
       if (!EmptyQueue(Q))
       {
              value = Q.base[Q.front];
              Q.front = (Q.front+1)%MAXQUEUE;
       }
}
9、插入元素到队列
void InsertQueue(struct SqQueue &Q, int value)
{
       if ((Q.rear + 1) % MAXQUEUE == Q.front)
       {
              printf("队列已满\n");
              return;
       }
       Q.base[Q.rear] = value;
       Q.rear = (Q.rear + 1) % MAXQUEUE;
}
10、遍历队列元素
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
