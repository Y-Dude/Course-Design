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







/*解法一
#include
main()
{ int i,j,n=0,a[17][17]={0};
   while(n<1 || n>16)
   { printf("请输入杨辉三角形的行数:");
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
点评：解法一是一般最容易想到的解法，各部分功能独立，程序浅显易懂。
解法二
#include
main()
{ int i,j,n=0,a[17][17]={1};
   while(n<1 || n>16)
   { printf("请输入杨辉三角形的行数:");
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
点评：解窢二是在解法一的基础上，把第一列置为1的命令移到下面的双重循环中，减少了一个循环。注意初始化数组的变化。
解法三
#include
main()
{ int i,j,n=0,a[17][17]={0,1};
   while(n<1 || n>16)
   { printf("请输入杨辉三角形的行数:");
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
点评：解法三是在解法一、二的基础上，把第一列置为1的命令去掉了，注意初始化数组的变化。
解法四
#include
main()
{ int i,j,n=0,a[17][17]={0,1};
   while(n<1 || n>16)
   { printf("请输入杨辉三角形的行数:");
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
点评：解法四是在解法三的基础上，把计算和打印合并在一个双重循环中。
解法五
#include<stdio.h>
int main()
{ int i,j,n=0,a[17]={1},b[17];
   while(n<1 || n>16)
   { printf("请输入杨辉三角形的行数:");
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
点评：解法一到解法四都用了二维数组，占用的空间较多。而解法五只使用了两个一维数组。
解法六
#include
main()
{ int i,j,n=0,a[17]={0,1},l,r;
   while(n<1 || n>16)
   { printf("请输入杨辉三角形的行数:");
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
