#include<iostream>
#include<ctime>
using namespace std;
int main()
{
    time_t t;
    /*time(&t);*/
    cout<<"��ǰʱ��Ϊ��"<<endl;
    cout<<ctime(&t)<<endl;
    return 0;
}
