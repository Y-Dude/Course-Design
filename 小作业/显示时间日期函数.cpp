#include<iostream>
#include<ctime>
using namespace std;
int main()
{
    time_t t;
    /*time(&t);*/
    cout<<"当前时间为："<<endl;
    cout<<ctime(&t)<<endl;
    return 0;
}
