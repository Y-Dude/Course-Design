#include<stdio.h>
#include"windows.h"
int i,n;int j=0;
struct bound
{
    int low;
    int high;
};
DWORD WINAPI Thread1(PVOID para)
 {
   int low=1;
   int high=n;
  for(i=low;i<high;i++){   j=j*i;  }
    return 0; }
int main()
{ bound qw1,qw2;
  qw1.low=1;
 qw1.high =n/2;
           HANDLE ThreadHandle1=CreateThread(NULL,0,Thread1,&qw1,0,NULL);
 qw2.low=n/2+1;
 qw2.high=n;
HANDLE ThreadHandle2 =CreateThread(NULL,0,Thread1,&qw2,0,NULL);
 HANDLE Garlandless[2]= {ThreadHandle1,ThreadHandle2};
WaitForMultipleObjects(2,Garlandless,TRUE,INFINITE);
  printf("j=%d",j);
 return 0;
}
