#include <bits/stdc++.h>
using namespace std;

long fun(string s)
{
    if (s == "atk")
        return 0;
    else if (s == "atkper")
        return 1;
    else if (s == "def")
        return 2;
    else if (s == "spd")
        return 3;
    return -1;
}

int main()
{
    vector<vector<long>> soul(6, vector<long>(4, 0));

    for (long i = 0;i < 6;i++)
    {
        string mainElement;
        long t;
        int n;

        cin >> mainElement;
        cin >> t;
        soul[i][fun(mainElement)] += t;

        cin >> n;
        for (int j = 0;j < n;j++)
        {
            string s;
            long t;
            cin >> s;
            cin >> t;
            soul[i][fun(s)] += t;
        }
        cin.get();
    }
    vector<long> res(4, 0);

    // for (int i = 0;i < 6;i++)
    // {
    //     for (int j = 0;j < 4;j++)
    //         cout << soul[i][j] << ' ';
    //     cout << endl;
    // }


    for (int i = 0;i < 4;i++)
        for (int j = 0;j < 6;j++)
            res[i] += soul[j][i];

    cout << "atk " << res[0] << endl;
    cout << "atkper " << res[1] << endl;
    cout << "def " << res[2] << endl;
    cout << "spd " << res[3] << endl;

    return 0;
}