Լɪ������(O(n)���㷨)�����㷨
/*
Description

��m�����Ӵ�1��m���Ϻţ������Χ����һ��Ȧ����1�ź��ӿ�ʼ����ÿ����nʱ���������ĺ��Ӽ��뿪Ȧ�ӣ�Ȼ�����һ�����ӿ�ʼ���ٴ�1��ʼ������˲��ϵ�����ȥ��ֻ��ֻʣ�����һ�����ӣ���ʣ�µĺ����Ǽ��ţ�

Input

����Ϊһ�������ԣ�ÿ��������ռһ�У������Եĵ�һ��������ʾm�������ӵĸ������ڶ���������ʾn����������n�ĺ��ӽ��뿪��

0��m��10000, n��0

������0 0��Ϊ������

Output

ÿ�����������һ�����������ÿ�����ռһ�С�

���һ������0 0�����������

Sample Input

8 3
5 2
0 0

Sample Output

7
3
*/

/*NO.1 (O(n) )�㷨*/

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

/*NO.2 ����ģ��*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

/*���ã���������,(i+1)%m...*/
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
                    printf("%d ",k+1); /*�������*/
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

/*NO.3ѭ������ģ��*/

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

    /*����ѭ������*/
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

    q -> next = head ; /*�����һ������ָ��ͷ�������͹�����ѭ������*/



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
