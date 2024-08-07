#include<bits/stdc++.h>
using namespace std;

int main()
{
    long n, a, b;
    cin >> n >> a >> b;
    long res = 0;
    long k = 0;
    long cnt = 0;
    char t;
    while (cin >> t)
    {
        res += a + k * b;
        if (t == 'o')
            k++;
        else k = 0;
    }

    cout << res;

    return 0;
}