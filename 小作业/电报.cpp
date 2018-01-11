#include<iostream>
using namespace std;
int main()
{
    int a[3],i,j,b;
    for(i=0;i<3;i++)
        cin>>a[i];
    for(j=0;j<2;j++)
        for(i=0;i<2;i++)
        if(a[i]>a[i+1])
        {b=a[i];
        a[i]=a[i+1];
        a[i+1]=b;}
    for(i=0;i<3;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
