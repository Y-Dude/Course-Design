/*��Ŀ����
���еĻ�����ϵΪ��1��2��5��10��20��50��100����������㷨������Ҫ�����ٵĻ�����֧��ָ�����N��ÿ�ֻ�����Ҫʹ�õ�������

����
��һ��Ϊ������������n��n��1000�� ����n�У�ÿ��Ϊһ������������ÿ����������Ϊһ������0������Ŀ����m��0��m��10000��

���
��ÿ���������������һ���ɿո�����7���������ֱ��ʾ1Ԫ��2Ԫ��5Ԫ��10Ԫ��20Ԫ��50Ԫ��100Ԫ��ʹ�õ�������

��������
2
15
189

�������
0 0 1 1 0 0 0
0 2 1 1 1 1 1

*/
#include <iostream>
using namespace std;
const static int money[7] = {1,2,5,10,20,50,100};
void init(int * amount)
{
    for(int i = 0; i < 7; i++)
        amount[i] = 0;
}
int main()
{
    int count = 0;
    cin >>  count;
    int num;
    int amount[7];
    init(amount);
    while(count != 0)
    {
        count--;
        cin >> num;
        if(num < 0 || num > 10000)
        {
            break;
        }
        for(int i = 6; i >= 0 ; i--)
        {
            if(num>=money[i])
            {
                amount[i] = num/money[i];
                num = num%money[i];
            }
        }
        for(int i = 0; i <= 6 ; i++)
        {
            cout << amount[i] << " ";
        }
        cout << endl;
        init(amount);
    }
    return 0;
}
