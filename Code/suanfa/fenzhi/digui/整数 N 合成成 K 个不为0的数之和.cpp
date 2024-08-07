#include <iostream>
using namespace std;
int f(int n, int k);
int main(int argc, char const *argv[])
{
    cout << "请输入n与k" << endl;
    int n, k;
    cin >> n;
    cin >> k;
    cout << f(n, k) << endl;
    return 0;
}

int f(int n, int k)
{
    if (n < k)
    {
        return 0;
    }
    else if ((n == k) || (k == 1))
    {
        return 1;
    }
    else
    {
        return f(n - 1, k - 1) + f(n - k, k);
    }
}
/* 关于将一个整数 N 合成成 K 个不为0的数之和，能够应用递归加动态规划来停止快速运算。

    递推公式为：

        f(n, k) = f(n - 1, k - 1) + f(n - k, k)

            递归出口为：
f(n, k) = 1,当 k == 1 或 n == k;（很明显，只要一个袋子，或者袋子数和球数相同时只要一种分法）

f(n, k) = 0, 当 n < k；（球数比袋子数少，则必然存在尚未应用的袋子，无解）

接下来停止剖析：

f(n-1, k-1）怎样了解呢，就是把第 1 个数放成 1，然后把剩下的 n-1 这个数分红 k-1 份。f(n-1, k-1）就是原n，k问题中第一个数是 1 的一切分的办法数；
f(n-k, k) 就是原n，k问题中第一个数不是 1（大于1），能够分的办法数。这是一个关键点。认真剖析，相当于给 k 个位置，每个位置先放一个 1，（相当于每个袋子都有1个球）。接下来剩下的 n-k ，这个数字再往这 k 个位置上分，（相当于把剩下的球分给袋子，仍保证应用一切袋子）这能够保证第一个位置至少比1大（第一个袋子的球数大于1）。
 */