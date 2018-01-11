约瑟环问题(O(n)简单算法)多种算法
/*
Description

将m个孩子从1到m编上号，按序号围坐成一个圈，从1号孩子开始数，每数到n时，被数到的孩子即离开圈子，然后从下一个孩子开始，再从1开始数，如此不断地数下去，只到只剩下最后一个孩子，问剩下的孩子是几号？

Input

输入为一组整数对，每个整数对占一行，整数对的第一个整数表示m，即孩子的个数，第二个整数表示n，即被数到n的孩子将离开。

0＜m＜10000, n＞0

输入以0 0作为结束。

Output

每组整数对输出一个结果整数，每个输出占一行。

最后一行输入0 0不产生输出。

Sample Input

8 3
5 2
0 0

Sample Output

7
3
*/

/*NO.1 (O(n) )算法*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int m,r;
    int i , j, s=0;

    scanf("%d %d",&m,&r);

    for(i=1 ; i<=m ; i++)
    {
       s = (s+r) % i ;
    }

    printf("s=%d ",s+1);

    system("pause");

    return 0 ;
}

/*NO.2 数组模拟*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

/*利用：求余特性,(i+1)%m...*/
int main(void)
{
    int a[MAX]={0} ;
    int m,r,i,j,k,h;

    scanf("%d %d",&m,&r) ;
    k = 0 ;
    for(i=1 ; i<= m; i++)
    {
            for(j=0 ; ; )
            {
             if(a[k] == 0)
             {

                j ++ ;

                if ( j < r)
                k = (k+1)%m ;
                else
                {
                    a[k] = 1 ;
                    printf("%d ",k+1); /*输出正解*/
                    if(i != m)
                    k = (k+1) % m ;
                    break ;
                }
              }
             else
             k = (k+1) % m ;
            }
    }

    printf("last = %d ",k+1) ;
    system("pause");
    return 0 ;
}

/*NO.3循环链表模拟*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
        int num ;
        struct list *next ;
}LIST ;


int main(void)
{
    LIST *head=NULL,*p,*q;

    long i,j,k,m,r ;

    scanf("%ld %ld",&m,&r) ;
    if( m <= 1)
    {
        printf("1 ");
        return 0;
    }

    /*建立循环链表*/
    p = (LIST *)malloc(sizeof(LIST));
    p->num = 1 ;
    p->next = NULL ;
    head = p ;
    q = p ;
    for(i=2 ; i<= m; i++)
    {
    p = (LIST *)malloc(sizeof(LIST));
    p->num = i;
    p->next= NULL ;
    q->next=p ;
    q = p ;
    }

    q -> next = head ; /*将最后一个结点的指向头，这样就构成了循不链表*/



    p= head ;

    while (q -> next != q)
    {
          for(i=1; i< r ; i++)
          {
          q = p ;
          p = p->next ;
          }
          q -> next = p->next ;
          p = q->next ;
    }

    printf("last=%d ",p->num);
    system("pause");






    return 0 ;
