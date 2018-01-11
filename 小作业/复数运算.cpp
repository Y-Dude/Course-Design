#include<iostream>
using namespace std;
class Complex
{
public:
    double r;
    double i;
    Complex operator + (Complex &c2)
	{
		Complex c;
		c.r=r+c2.r;
		c.i=i+c2.i;
		return c;
    }
    Complex operator - (Complex &c2)
    {
        Complex c;
        c.r=r-c2.r;
        c.i=i-c2.i;
        return c;
    }
	Complex operator * (Complex &c2)
	{
	    Complex c;
	    c.r=r*c2.r-i*c2.i;
	    c.i=r*c2.i+i*c2.r;
	    return c;
	}

    void display()
    {
        cout<<"("<<r<<","<<i<<"i)"<<endl;
    }
};
Complex c1,c2,c3;
int main()
{
	char f;
    cout<<"请输入两个复数的实部与虚部:"<<endl;
    cout<<"第一个"<<endl;
    cin>>c1.r>>c1.i;
    cout<<"第二个"<<endl;
    cin>>c2.r>>c2.i;
    cout<<"请输入运算符:"<<endl;
    cin>>f;
    if(f=='+'){c3=c1+c2;cout<<"c1+c2=";}
	else if(f=='-'){c3=c1-c2;cout<<"c1-c2=";}
	else if(f=='*'){c3=c1*c2;cout<<"c1+c2=";}
	c3.display();
    return 0;
}
