#include<stdio.h>
#include<string.h>
int main()
{
    char T[100];/*����T��0���������������ĳ���*/
    int next[100],i=1,j=0,k;
    next[i]=0;
    gets(T+1);//scanf("%s",T+1);
    printf("%d ",next[i]);
    k=strlen(T+1);
    while(i<k){
        if(j==0 || T[i]==T[j])
        {
            i++;
            j++;
            next[i]=j;
            printf("%d ",next[i]);
        }
        else{
        j=next[j];
        }
    }
    return 0;
}
