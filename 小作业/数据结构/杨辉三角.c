#include <stdio.h>
int len (int x)
{
	int i = 1;
	while (x>=10)
	{
		x=x/10;
		i++;
	}
	return i;
}
int main()
{
int i,j,n,max,Mlen,k;
int a[30][30];
while(scanf("%d",&n)!=EOF){
        max=1;
        for(i=0;i<n;i++)
        {
            a[i][0]=1;
            a[i][i]=1;
            }
            for(i=2;i<n;i++)
                for(j=1;j<i;j++)
                {a[i][j]=a[i-1][j-1]+a[i-1][j];
                if(max<a[i][j])
                max=a[i][j];}
              Mlen=len(max);
            for(i=0;i<n;i++)
                {
                    for(j=0;j<=i;j++){
                            if(j==0)
                            printf("%d",a[i][j]);
                    else{
                            for(k=Mlen-len(a[i][j])+1;k>0;k--)
                                printf(" ");
                        printf("%d",a[i][j]);}
                    }
                    printf("\n");
                    }printf("\n");
                    }
                    return 0;
}







/*�ⷨһ
#include
main()
{ int i,j,n=0,a[17][17]={0};
   while(n<1 || n>16)
   { printf("��������������ε�����:");
     scanf("%d",&n);
   }
   for(i=0;i<=n;i++)
     a[i][0]=1;
   for(i=1;i
     for(j=1;j<=i;j++)
       a[i][j]=a[i-1][j-1]+a[i-1][j];
   for(i=0;i<=n;i++)
   { for(j=0;j<=i;j++)
       printf("%5d",a[i][j]);
     printf("\n");
   }
}
�������ⷨһ��һ���������뵽�Ľⷨ�������ֹ��ܶ���������ǳ���׶���
�ⷨ��
#include
main()
{ int i,j,n=0,a[17][17]={1};
   while(n<1 || n>16)
   { printf("��������������ε�����:");
     scanf("%d",&n);
   }
   for(i=1;i
   { a[i][0]=1;
     for(j=1;j<=i;j++)
       a[i][j]=a[i-1][j-1]+a[i-1][j];
   }
     for(i=0;i
     { for(j=0;j<=i;j++)
         printf("%5d",a[i][j]);
       printf("\n");
     }
}
�������ⷠ�����ڽⷨһ�Ļ����ϣ��ѵ�һ����Ϊ1�������Ƶ������˫��ѭ���У�������һ��ѭ����ע���ʼ������ı仯��
�ⷨ��
#include
main()
{ int i,j,n=0,a[17][17]={0,1};
   while(n<1 || n>16)
   { printf("��������������ε�����:");
     scanf("%d",&n);
   }
   for(i=1;i<=n;i++)
   for(j=1;j<=i;j++)
     a[i][j]=a[i-1][j-1]+a[i-1][j];
   for(i=1;i<=n;i++)
   { for(j=1;j<=i;j++) printf("%5d",a[i][j]);
      printf("\n");
   }
}
�������ⷨ�����ڽⷨһ�����Ļ����ϣ��ѵ�һ����Ϊ1������ȥ���ˣ�ע���ʼ������ı仯��
�ⷨ��
#include
main()
{ int i,j,n=0,a[17][17]={0,1};
   while(n<1 || n>16)
   { printf("��������������ε�����:");
     scanf("%d",&n);
   }
   for(i=1;i<=n;i++)
   { for(j=1;j<=i;j++)
     { a[i][j]=a[i-1][j-1]+a[i-1][j];
       printf("%5d",a[i][j]);
     }
     printf("\n");
   }
}
�������ⷨ�����ڽⷨ���Ļ����ϣ��Ѽ���ʹ�ӡ�ϲ���һ��˫��ѭ���С�
�ⷨ��
#include<stdio.h>
int main()
{ int i,j,n=0,a[17]={1},b[17];
   while(n<1 || n>16)
   { printf("��������������ε�����:");
     scanf("%d",&n);
   }
   for(i=0;i<=n;i++)
   { b[0]=a[0];
     for(j=1;j<=i;j++)
        b[j]=a[j-1]+a[j];
     for(j=0;j<=i;j++)
     { a[j]=b[j];
       printf("%5d",a[j]);
     }
     printf("\n");
   }
   return 0;
}
�������ⷨһ���ⷨ�Ķ����˶�ά���飬ռ�õĿռ�϶ࡣ���ⷨ��ֻʹ��������һά���顣
�ⷨ��
#include
main()
{ int i,j,n=0,a[17]={0,1},l,r;
   while(n<1 || n>16)
   { printf("��������������ε�����:");
     scanf("%d",&n);
   }
   for(i=1;i<=n;i++)
   { l=0;
     for(j=1;j<=i;j++)
     { r=a[j];
       a[j]=l+r;
       l=r;
       printf("%5d",a[j]);
     }
     printf("\n");
   }
}*/
