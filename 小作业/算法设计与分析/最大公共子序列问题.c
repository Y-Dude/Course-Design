/*��Ŀ����
������X=(x1, x2, .., xm)��������������Ϊ(xi1, xi2, .., xik)��i1<i2<..<ik���������������X=(x1, x2, .., xm)��Y=(y1, y2, .., yn)������������еĳ��ȡ�
����
����Ϊ�����У�ÿ����һ��������Ŀ��ÿ�а����������Ȳ�����100���ַ������м��ÿո������
���
��ÿһ���е������ַ��������㲢�������󹫹������еĳ��ȡ�ÿһ������ļ��������һ�С�
��������
a a
a ab
abcd dcba
abcd bc
abcdef aabacfe
�������
1
1
1
2
4
*/


#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
    int i,j,len1,len2;
    char x[N],y[N];
    while(scanf("%s %s",x,y)!=EOF)
    {
        int c[N][N];
    len1=strlen(x);
    len2=strlen(y);
    for(i=0;i<len1;i++)
        c[i][0]=0;
    for(i=0;i<len2;i++)
        c[0][i]=0;
    for(i=1;i<=len1;i++)
        for(j=1;j<=len2;j++)
        if(x[i]==y[j])
        c[i][j]=c[i-1][j-1]+1;
        else
            if(c[i-1][j]>c[i][j-1])
            c[i][j]=c[i-1][j];
            else
                c[i][j]=c[i][j-1];
            printf("%d\n",c[len1][len2]);
            }
        return 0;
}


/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *pln1 , *pln2;
char a[10010] , b[10010];
int main()
{
    int i , j , lena , lenb ;
    while(scanf("%s %s",a,b)!=EOF)
    {
    lena = strlen(a);
    lenb = strlen(b);
    pln1 = (int*)calloc( lenb + 1 , sizeof(int) );
    memset( pln1 , 0 , sizeof(pln1) );
    pln2 = (int*)calloc( lenb + 1 , sizeof(int) );
    memset( pln2 , 0 , sizeof(pln2) );
    for( i = 1 ; i <= lena ; i++ )
    {
        for( j = 1 ; j <= lenb ; j++ )
        {
            if( a[i-1] == b[j-1] )
            {
                pln2[j] = pln1[j-1] + 1;
            }
            else
            if( pln1[j] >= pln2[j-1] )
            {
                pln2[j] = pln1[j];
            }
            else
            {
                pln2[j] = pln2[j-1];
            }
        }
        free(pln1);
        pln1 = pln2;
        pln2 = (int*)calloc( lenb + 1 , sizeof(int) );
        memset( pln2 , 0 , sizeof(pln2) );
    }
    printf( "%d\n" , pln1[lenb] );
    }
    return 0;
}
*/
