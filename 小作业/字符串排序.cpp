#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s2,s3,t;
    cin>>s1>>s2>>s3;
    if(s1>s2){t=s1;s1=s2;s2=t;}
    if(s2>s3){t=s2;s2=s3;s3=t;}
    if(s1>s2){t=s1;s1=s2;s2=t;}
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    return 0;
}
