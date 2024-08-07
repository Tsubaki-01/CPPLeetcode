#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s, t, target;
    getline(cin, s);
    getline(cin, s);
    getline(cin, t);
    getline(cin, target);


    for (int i = 0;i < n;i++)
    {
        if (target[i] != s[i] && target[i] != t[i])
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}