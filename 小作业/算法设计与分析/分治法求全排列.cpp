/*题目2：全排列
题目描述
给定n个字符{r1,r2,…,rn}，要求生成这n个字符的全排序。
生成全排列思想如下：
设R={r1,r2,…,rn}是要进行排列的n个元素，Ri=R-{ri}。
集合X中元素的全排列记为perm(X)。
(ri)perm(X)表示在全排列perm(X)的每一个排列前加上前缀得到的排列。R的全排列可归纳定义如下：
当n=1时，perm(R)=(r)，其中r是集合R中唯一的元素；
当n>1时，perm(R)由(r1)perm(R1)，(r2)perm(R2)，…，(rn)perm(Rn)构成。
输入
输入包括若干个用例，第一行为一个正整数k(1<=k<=10)，表示用例个数。
每个用例占两行，其中第一行为该用例字符的个数n（1<=n<=5），第二行为n个字符，字符可以是数字和大小写字母，字符之间用空格隔开。
可以假定给定同一用例中不出现相同的字符。
输出
输出每个用例的全排列，每一个排列占一行。各用例全排序之间用一空行隔开。
样例输入
2
2
1 2
3
a c b

样例输出
12
21

acb
abc
cab
cba
bca
bac*/
#include <iostream>
using namespace std;
bool OK(char list[],int k,int i)
{
 if(i>k)
  for(int t=k;t<i;t++)
   if(list[t]==list[i])return 1;
   return 0;
}
void Perm(char list[],int k,int m)
{
 if(k==m)
 {
  for(int i=1;i<=m;i++)cout<<list[i];
  cout<<endl;
 }
 else
  for(int i=k;i<=m;i++)
  {
   if(!OK(list,k,i))
   {
    swap(list[k],list[i]);
       Perm(list,k+1,m);
       swap(list[k],list[i]);
   }
  }
}
int main()
{
 char a[100];
 int n,m;
 cin>>n;
 while(n!=0)
 {
  cin>>m;
  for(int i=1;i<=m;i++)cin>>a[i];
  Perm(a,1,m);
  cout<<endl;
  n--;
 }
 return 0;
}



#include<stdio.h>
void perm(int* data, int n, int curr)
{
if (curr==n-1)
{
for(int i = 0; i < n; ++i)
printf("%d ", data[i]);
printf("\n");
}
else
{
for (int i = curr; i < n; ++i)
{
int t;
t = data[curr], data[curr] = data[i], data[i] = t;
perm(data, n, curr+1);
t = data[curr], data[curr] = data[i], data[i] = t;
}
}
}
int main()
{
int array[128] = {0};
int n = 0, i = 0;
while(scanf("%d", &n)!=EOF)
{
for (i = 0; i < n; ++i) array[i] = i+1;
perm(array, n, 0);
}
return 0;
}
