#include<stdio.h>
#include<string.h>
int main()
{
    char T[100];
    while(gets(T)!=EOF){
    int next[100],i=0,j=-1,k;
    next[i]=-1;
    printf("%d ",next[i]);
    k=strlen(T);
    while(i<k-1){
        if(j==-1 || T[i]==T[j])
        {
            i++;
            j++;
            if(T[i]!=T[j])next[i]=j;
            else next[i]=next[j];
            printf("%d ",next[i]);
        }
        else{
        j=next[j];
        }
    }
    printf("\n");
    }
    return 0;
}
