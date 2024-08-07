/* #include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    else return a[1] < b[1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> box(n, vector<int>(3, 0));
    for (int i = 0;i < n;++i)
        for (int j = 0;j < 3;++j)
            cin >> box[i][j];

    sort(box.begin(), box.end(), cmp);
    // 0堆 1不堆
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
    for (int i = 0;i < dp.size();++i)
        dp[i][i][0] = box[i][2], dp[i][i][1] = 0;

    for (int i = 0;i < dp.size();i++)
    {
        int len = box[i][0];
        int wid = box[i][1];
        for (int j = i + 1;j < dp[0].size();j++)
            if (box[j][1] < wid && box[j][0] < len)
            {
                dp[i][j][0] = max(dp[i][j - 1][0], dp[i][j - 1][1]) + box[j][2];
                len = box[j][0];
                wid = box[j][1];
                // 这边更新少了情况

            }
            else {
                dp[i][j][1] = max(dp[i][j - 1][0], dp[i][j - 1][1]);
                dp[i][j][0] = max(dp[i][j - 1][0], dp[i][j - 1][1]);
            }

    }

    int res = 0;
    for (int i = 0;i < n;i++)
    {
        res = max({ dp[i][n - 1][0],dp[i][n - 1][1],res });
    }
    cout << res;
    return 0;
}
// 64 位输出请用 printf("%lld") */



leetcode300 最长递增子序列