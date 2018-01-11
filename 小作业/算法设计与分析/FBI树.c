/*题目描述
我们可以把由“0”和“1”组成的字符串分为三类：全“0”串称为B串，全“1”串称为I串，既含“0”又含“1”的串则称为F串。
 FBI树是一种二叉树 ，它的结点类型也包括F结点，B结点和I结点三种。由一个长度为2N的“01”串S可以构造出一棵FBI树T，递归的构造方法如下：
  1) T的根结点为R，其类型与串S的类型相同；
  2) 若串S的长度大于1，将串S从中间分开，分为等长的左右子串S1和S2；由左子串S1构造R的左子树T1，由右子串S2构造R的右子树T2。现在给定一个长度为2N的“01”串，
  请用上述构造方法构造出一棵FBI树，并输出它的后序遍历序列。
输入
输入的第一行是一个整数N（0 <= N <= 10），第二行是一个长度为2N的“01”串。
输出
输出包括一行，这一行只包含一个字符串，即FBI树的后序遍历序列。
样例输入
3
10001011
样例输出
IBFBBBFIBFIIIFF
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[1025];
char put[3] = {'B', 'I' ,'F'};

int srch(int start, int end)
{
    int i, j;
    if(start == end){
        printf("%c", put[str[start] - '0']);
        return str[start] - '0';
    }
    i = srch(start, (start + end) / 2);
    j = srch((start + end) / 2 + 1, end);
    if(i == j){
        printf("%c", put[i]);
        return i;
    }else{
        printf("%c", 'F');
        return 2;
    }
}

int main()
{
    int n;
    scanf("%d\n", &n);
    scanf("%s", str);
    srch(0, strlen(str) - 1);
    printf("\n");
    return 0;
}


#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
char nodeType(string s);
void substring(string s);
vector <char> v;
int main()
{
    int n;
    string s;
    cout << "please input n:" << endl;
    cin >> n;
    while (n<0 || n>10)  //n大小不对
    {
        cout << "input error! please input again:" << endl;
        cin >> n;
    }
    cout << "please input s:" << endl;
    cin >> s;
    while (s.size() != pow(2, n))  //字符串长度不对
    {
        cout << "input error! please input again:" << endl;
        cin >> s;
    }
    //将字符串0/1改成B/I,便于求串类型
    for (int i=0; i<s.size(); i++)
    {
        if (s[i] == '1')
        {
            s[i] = 'I';
        }
        else if(s[i] == '0')
        {
            s[i] = 'B';
        }
        else   //字符串含有非01字符，退出
        {
            exit(-1);
        }
    }

    substring(s);
    string temp = "";
    //容器v中的串类型反向输出
    for (i=v.size()-1; i>=0; i--)
    {
        temp += v[i];
    }
    cout << temp << endl;

    return 0;
}
//递归求s的字串类型，先右字串，后左字串，
//所得类型依次存入vector容器v，最后反向输出即为后序遍历
void substring(string s)
{
    v.push_back(nodeType(s));  //s的串类型存入v
    if (s.size() > 1)
    {
        string s1, s2;
        //拆分s串
        s1 = s.substr(0, s.size()/2);
        s2 = s.substr(s.size()/2, s.size()/2);

        //递归求子串类型, 先右后左最后反向输出v即为后序遍历
        substring(s2);
        substring(s1);
    }
}
//判断s串的类型(F/B/I)
char nodeType(string s)
{
    char type = s[0];
    for (int i=1; i<s.size(); i++)
    {
        if (s[i] != type)
        {
            type = 'F';
            break;
        }
    }

    return type;
}
