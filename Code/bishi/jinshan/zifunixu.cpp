#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string function1(string& s)
{
    stack<char> sta;
    string res;
    for (auto c : s)
    {
        sta.push(c);
    }
    while (!sta.empty())
    {
        char c = sta.top();sta.pop();
        res.push_back(c);
    }
    return res;
}

int main() {
    string str;
    char s[10000] = { 0 };
    cin.getline(s, 10000, '\n');
    str = s;
    // str.pop_back();
    string res = function1(str);
    cout << res;

}

// 64 位输出请用 printf("%lld")
