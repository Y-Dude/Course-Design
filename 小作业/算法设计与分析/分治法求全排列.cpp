/*��Ŀ2��ȫ����
��Ŀ����
����n���ַ�{r1,r2,��,rn}��Ҫ��������n���ַ���ȫ����
����ȫ����˼�����£�
��R={r1,r2,��,rn}��Ҫ�������е�n��Ԫ�أ�Ri=R-{ri}��
����X��Ԫ�ص�ȫ���м�Ϊperm(X)��
(ri)perm(X)��ʾ��ȫ����perm(X)��ÿһ������ǰ����ǰ׺�õ������С�R��ȫ���пɹ��ɶ������£�
��n=1ʱ��perm(R)=(r)������r�Ǽ���R��Ψһ��Ԫ�أ�
��n>1ʱ��perm(R)��(r1)perm(R1)��(r2)perm(R2)������(rn)perm(Rn)���ɡ�
����
����������ɸ���������һ��Ϊһ��������k(1<=k<=10)����ʾ����������
ÿ������ռ���У����е�һ��Ϊ�������ַ��ĸ���n��1<=n<=5�����ڶ���Ϊn���ַ����ַ����������ֺʹ�Сд��ĸ���ַ�֮���ÿո������
���Լٶ�����ͬһ�����в�������ͬ���ַ���
���
���ÿ��������ȫ���У�ÿһ������ռһ�С�������ȫ����֮����һ���и�����
��������
2
2
1 2
3
a c b

�������
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
