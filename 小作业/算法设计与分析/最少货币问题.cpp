/*题目描述
现行的货币体系为（1、2、5、10、20、50、100），请设计算法，计算要用最少的货币数支付指定金额N，每种货币需要使用的数量。

输入
第一行为测试用例个数n，n≤1000。 后面n行，每行为一个测试用例，每个测试用例为一个大于0的整数目标金额m，0≤m≤10000。

输出
对每个测试用例，输出一行由空格间隔的7个整数，分别表示1元、2元、5元、10元、20元、50元、100元所使用的数量。

样例输入
2
15
189

样例输出
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
