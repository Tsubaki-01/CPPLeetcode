#include <iostream>
#include <vector>
#include <string>

using namespace std;

int m, n;

void LCS(vector<vector<int>> *dp, string A, string B)
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (A[i - 1] == B[j - 1])
                (*dp)[i][j] = (*dp)[i - 1][j - 1] + 1;
            else
                (*dp)[i][j] = max((*dp)[i - 1][j], (*dp)[i][j - 1]);
        }
}

int main()
{
    string A = "ACCGGTCGAGATGCAG";
    string B = "GTCGTTCGGAATGCAT";
    m = A.length();
    n = B.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    LCS(&dp, A, B);

    cout << dp[m][n] << endl;

    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (A[i] == B[j])
            lcs = A[i] + lcs, i--, j--;
        else
            dp[i - 1][j] > dp[i][j - 1] ? (i--) : (j--);
    }

    cout << lcs << endl;

    return 0;
}