#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int function1(vector<string> s)
{
    int a = stoi(s[1]);
    int b = stoi(s[2]);
    if (s[0][0] == 'A' || s[0][0] == 'a')
        return a + b;
    if (s[0][0] == 'S' || s[0][0] == 's')
        return a - b;
    if (s[0][0] == 'M' || s[0][0] == 'm')
        return a * b;
    if (s[0][0] == 'D' || s[0][0] == 'd')
        if (b == 0)
            return INT_MIN;
        else return a / b;
    return INT_MIN;
}

int main() {
    vector<string> str;
    string t;
    while (cin >> t)
        str.push_back(t);

    int res = function1(str);
    if (res != INT_MIN)
        cout << res;
    else cout << "ERROR";
    return 0;
}