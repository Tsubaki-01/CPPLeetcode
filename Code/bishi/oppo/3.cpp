#include<bits/stdc++.h>
using namespace std;

int function1(int a)
{
    int res = 0;
    while ((a & 1) == 0)
    {
        res++;
        a = a >> 1;
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
    }

    unordered_map<int, int> map;
    int min_res = INT_MAX;
    for (int i = 0;i < n;i++)
    {
        map[i] = function1(a[i]);
    }


    int left = 0;
    int right = 0;
    int temp = map[0];
    while (left <= right && left < n && right < n)
    {
        if (temp >= k)
        {
            min_res = min(min_res, right - left + 1);
            temp -= map[left];
            left++;
        }
        else
        {
            right++;
            temp += map[right];
        }
    }


    if (min_res != INT_MAX)
        cout << min_res << endl;
    else cout << -1 << endl;


    return 0;
}