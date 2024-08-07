#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n 次数 m 总数 i 为1~7的数。m=n次i的和
// 求和为m的组合中i（1~7）分别出现的最大次数

int main() {
    int n, m;
    cin >> n >> m;

    // dp[i][j][k] 表示前 i 次挑选中，总和为 j 时，数 k 出现的最大次数
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(8, 0)));

    // 初始化
    for (int i = 1;i <= 7;i++)
        dp[1][i][i] = 1;

    // 动态规划填表
    // 2 10的组合 全部加1 就变成 3 11的组合  全部加2 就变成 3 12的组合...
    // 反过来推，就是想要得到 3 11 的组合就是 2 10的组合加1，2 9的组合加2，2 8的组合加3...
    /* 2  10
        0           3+7                  3+7+1
        0           4+6         +1       4+6+1
        1           5+5        -->>      5+5+1
        1           6+4                  6+4+1
        2           7+3                  7+3+1
        1
        1

     */
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            for (int x = 1; x <= 7; ++x) {
                if (j > x) {
                    for (int k = 1; k <= 7; ++k) {
                        if (dp[i - 1][j - x][k] != 0) {
                            if (x == k) {
                                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - x][k] + 1);
                            }
                            else {
                                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - x][k]);
                            }
                        }
                    }
                }
            }
        }
    }

    vector<int> res(8, 0);
    // 寻找每个数在所有组合中出现的最大次数
    for (int k = 1; k <= 7; ++k) {

        res[k] = dp[n][m][k];

    }

    // 输出结果
    for (int i = 1; i <= 7; ++i) {
        cout << res[i] << endl;
    }

    return 0;
}





// 回溯
// n是个数，m是和

/* vector<vector<int>> poss;
vector<int> t;

vector<int> res(8, 0);

unordered_map<int, pair<int, int>> map;

void backtracking(vector<int>& t, int& m_rest, int& n_rest)
{
    if (m_rest == 0 && n_rest == 0)
    {
        vector<int> temp(8, 0);
        for (auto item : t)
        {
            temp[item] += 1;
        }
        for (int i = 1;i <= 7;i++)
            res[i] = max(res[i], temp[i]);

        return;
    }

    int a = 1;
    if (t.size() == 0)
        a = int(m_rest / n_rest + 0.5);
    for (int i = a;i <= 7;i++)
    {
        if (m_rest - i < 0 || n_rest - 1 > m_rest - i || (n_rest - 1) * 7 < m_rest - 7)
            break;
        if ((n_rest - 1) * 7 < m_rest - i)
            continue;
        t.push_back(i);
        m_rest = m_rest - i;
        n_rest = n_rest - 1;
        backtracking(t, m_rest, n_rest); // 递归
        t.pop_back();
        m_rest = m_rest + i;
        n_rest = n_rest + 1;
    }
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    backtracking(t, m, n);

    for (int i = 1;i <= 7;i++)
        cout << res[i] << endl;

    return 0;
} */