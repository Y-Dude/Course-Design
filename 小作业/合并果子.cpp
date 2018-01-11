#include<iostream>
using namespace std;
int main()
{
    int a[10000],n,c,i,j;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
        if(n==1)cout<<a[0]<<endl;
        else
    {for(int j=0;j<n-1;j++)
        for(i=0;i<n-1;i++)
        if(a[i]>a[i+1])
        {c=a[i+1];
        a[i+1]=a[i];
        a[i]=c;}
    int s=a[0]+a[1],sum=a[0]+a[1];
        if(n==2)cout<<a[0]+a[1]<<endl;
        else
    {for(i=2;i<n;i++)
        {s=a[i]+s;
        sum=s+sum;}
    cout<<sum<<endl;}}
        return 0;
}
