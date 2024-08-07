#include <bits/stdc++.h>
using namespace std;


int main()
{
    string line1;
    string line2;
    getline(cin, line1);
    getline(cin, line2);

    vector<int> vec1;
    vector<int> vec2;
    for (auto c : line1)
        if (c == ' ')
            continue;
        else vec1.emplace_back(c - '0');
    for (auto c : line2)
        if (c == ' ')
            continue;
        else vec2.emplace_back(c - '0');
    int size1 = vec1.size();
    int size2 = vec2.size();
    vector<vector<int>> dp(size1, vector<int>(size2, 0));

    int index1 = 0;
    int max_len = 0;
    for (int i = 0;i < size1;i++)
        if (vec1[i] == vec2[0])
        {
            dp[i][0] = 1;
            max_len = 1;
            index1 = i;
        }
        else dp[i][0] = 0;
    for (int i = 0;i < size2;i++)
        if (vec1[0] == vec2[i])
        {
            dp[0][i] = 1;
            max_len = 1;
        }
        else dp[0][i] = 0;

    for (int i = 1;i < size1;i++)
        for (int j = 1;j < size2;j++)
            if (vec1[i] == vec2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_len)
                {
                    max_len = dp[i][j];
                    index1 = i;
                }
            }

    if (max_len == 0)
        cout << -1 << endl;
    else {
        for (int i = index1 - max_len + 1;i < index1;i++)
            cout << vec1[i] << ' ';
        cout << vec1[index1];
    }

    return 0;
}