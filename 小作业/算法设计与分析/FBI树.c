/*��Ŀ����
���ǿ��԰��ɡ�0���͡�1����ɵ��ַ�����Ϊ���ࣺȫ��0������ΪB����ȫ��1������ΪI�����Ⱥ���0���ֺ���1���Ĵ����ΪF����
 FBI����һ�ֶ����� �����Ľ������Ҳ����F��㣬B����I������֡���һ������Ϊ2N�ġ�01����S���Թ����һ��FBI��T���ݹ�Ĺ��췽�����£�
  1) T�ĸ����ΪR���������봮S��������ͬ��
  2) ����S�ĳ��ȴ���1������S���м�ֿ�����Ϊ�ȳ��������Ӵ�S1��S2�������Ӵ�S1����R��������T1�������Ӵ�S2����R��������T2�����ڸ���һ������Ϊ2N�ġ�01������
  �����������췽�������һ��FBI������������ĺ���������С�
����
����ĵ�һ����һ������N��0 <= N <= 10�����ڶ�����һ������Ϊ2N�ġ�01������
���
�������һ�У���һ��ֻ����һ���ַ�������FBI���ĺ���������С�
��������
3
10001011
�������
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
    while (n<0 || n>10)  //n��С����
    {
        cout << "input error! please input again:" << endl;
        cin >> n;
    }
    cout << "please input s:" << endl;
    cin >> s;
    while (s.size() != pow(2, n))  //�ַ������Ȳ���
    {
        cout << "input error! please input again:" << endl;
        cin >> s;
    }
    //���ַ���0/1�ĳ�B/I,����������
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
        else   //�ַ������з�01�ַ����˳�
        {
            exit(-1);
        }
    }

    substring(s);
    string temp = "";
    //����v�еĴ����ͷ������
    for (i=v.size()-1; i>=0; i--)
    {
        temp += v[i];
    }
    cout << temp << endl;

    return 0;
}
//�ݹ���s���ִ����ͣ������ִ��������ִ���
//�����������δ���vector����v������������Ϊ�������
void substring(string s)
{
    v.push_back(nodeType(s));  //s�Ĵ����ʹ���v
    if (s.size() > 1)
    {
        string s1, s2;
        //���s��
        s1 = s.substr(0, s.size()/2);
        s2 = s.substr(s.size()/2, s.size()/2);

        //�ݹ����Ӵ�����, ���Һ�����������v��Ϊ�������
        substring(s2);
        substring(s1);
    }
}
//�ж�s��������(F/B/I)
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
