#include<iostream>
using namespace std;
class DZ
{
private:
    int q,i;
    int A[100],B[100];
    char c[100],d[100];
public:
    void D1()
    {
        cout<<"����������λ��:"<<endl;
        cin>>q;
        cout<<"����������:"<<endl;
        for(i=0;i<q;i++)
            cin>>A[i];
        for(i=0;i<q;i++)
            cout<<A[i]<<" ";
    }
    void D2()
    {
        cout<<"����������λ��:"<<endl;
        cin>>q;
        cout<<"����������:"<<endl;
        for(i=0;i<q;i++)
            cin>>c[i];
        for(i=0;i<q;i++)
            cout<<c[i]<<" ";
    }
    void Z1()
    {
        cout<<"����������λ��:"<<endl;
        cin>>q;
        cout<<"����������:"<<endl;
        for(i=0;i<q;i++)
            cin>>B[i];
        for(i=q-1;i>=0;i--)
            cout<<B[i]<<" ";
    }
    void Z2()
    {
        cout<<"����������λ����"<<endl;
        cin>>q;
        cout<<"����������:"<<endl;
        for(i=0;i<q;i++)
            cin>>d[i];
        for(i=q-1;i>=0;i--)
            cout<<d[i]<<" ";
    }
};
DZ s1,s2,s3,s4;
int main()
{
    int a,b;
    cout<<"****Ҫ�����(1)������ջ(2)*********"<<endl;
    cout<<"**** 1.��       2.ջ      *********"<<endl;
    cin>>a;
    cout<<"***********************************"<<endl;
    cout<<"*****��ѡ����Ҫ���������:*********"<<endl;
    cout<<"**** 1.����������1        *********"<<endl;
    cout<<"**** 2.Ӣ�ļ�����������2  *********"<<endl;
    cin>>b;
    if(a==1&&b==1)s1.D1();
        else if(a==1&&b==2)s2.D2();
        else if(a==2&&b==1)s3.Z1();
        else if(a==2&&b==2)s4.Z2();
    return 0;
}
