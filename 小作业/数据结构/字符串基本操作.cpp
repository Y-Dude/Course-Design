#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct MyStr
{
    char a[100];
};
void InitStr(MyStr &l, char str[100])
{
    strcpy(l.a,str);
}
int StrLen(MyStr &l)
{
    int i;
    for(i=0;l.a[i]!='\0';)
        i++;
    return i;
}
void AppendStr(MyStr &l1,MyStr &l2)
{
    strcat(l1.a,l2.a);
}
void PrintStr(MyStr &l)
{
    puts(l.a);
}
void DestroyStr(MyStr &l){}

int main()
{
    char s1[100],s2[100];
    while(cin >> s1 >> s2){
        MyStr s,ss;
        InitStr(s,s1);
        InitStr(ss,s2);
        AppendStr(s,ss);
        PrintStr(s);
        cout << StrLen(s) << endl;
        DestroyStr(s);
        DestroyStr(ss);
    }

    return 0;
}
