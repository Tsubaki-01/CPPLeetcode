#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getSumOfZero(vector<int>& a, vector<int>& color, int left, int right)
{
    int blue = 1;
    int red = 1;
    int sum = 0;
    for (int i = left;i <= right;++i)
    {
        if (color[i] == 0)
        {
            blue = blue * a[i];
            while (blue % 10 == 0)
            {
                blue /= 10;
                ++sum;
            }
        }
        else
        {
            red *= a[i];
            while (red % 10 == 0)
            {
                red /= 10;
                ++sum;
            }
        }
    }

    return sum;

}

int function1(int n, int k, vector<int>& a, vector<int>& color)
{
    int left = 0;
    int right = 0;
    int minleft = 0, minright = 0;
    int minSize = INT_MAX;
    while (left < a.size() && left <= right && right < n)
    {
        if (getSumOfZero(a, color, left, right) >= k)
        {
            if (minSize > right - left - 1)
            {
                minSize = min(minSize, right - left + 1);
                minleft = left;
                minright = right;
            }

            ++left;
        }
        else
        {
            ++right;
        }
    }
    cout << minleft << endl << minright << endl;
    return minSize;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0;i < n;++i)
        cin >> a[i];
    string BR;
    cin >> BR;
    vector<int> color(n);
    for (int i = 0;i < n;++i)
    {
        color[i] = (BR[i] == 'B' ? 0 : 1);
    }

    // int n = 5;
    // int k = 2;
    // vector<int> a{ 1,4,15,8,5 };
    // vector<int> color{ 0,1,1,0,0 };


    int res = function1(n, k, a, color);
    cout << res << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")