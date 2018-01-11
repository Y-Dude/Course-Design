#include<stdio.h>
int main()
{
    char a[200];
    int i;
    int j;
    while(gets(a))
    {
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='#')
            {
                for(j=i;a[j]!='\0';j++)
                {
                    a[j-1]=a[j+1];
                }i=i-2;
            }
            if(a[i]=='@')
            {
                int k=0;
                for(j=i;a[j+1]!='\0';j++)
                {
                    a[k]=a[j+1];
                    k++;
                }
                a[k]='\0';
                i=0;
            }
        }printf("%s",a);
    }
}
