#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> f(2, vector<int>(5, 0));
vector<vector<int>> l(2, vector<int>(5, 0));

int a[2][5] = {7, 9, 3, 4, 8, 8, 5, 6, 4, 5};
int t[2][4] = {2, 3, 1, 3, 2, 1, 2, 2};

int Fastest_Way(vector<vector<int>> *f, vector<vector<int>> *l, int e1, int e2, int x1, int x2, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j == 0)
        {
            (*f)[0][0] = e1 + a[0][0];
            (*f)[1][0] = e2 + a[1][0];

            (*l)[0][j] = 1;
            (*l)[1][j] = 2;
        }
        else
        {
            if ((*f)[0][j - 1] + a[0][j] <= (*f)[1][j - 1] + t[1][j - 1] + a[0][j])
            {
                (*f)[0][j] = (*f)[0][j - 1] + a[0][j];
                (*l)[0][j] = 1;
            }
            else
            {
                (*f)[0][j] = (*f)[1][j - 1] + t[1][j - 1] + a[0][j];
                (*l)[0][j] = 2;
            }
            if ((*f)[1][j - 1] + a[1][j] <= (*f)[0][j - 1] + t[0][j - 1] + a[1][j])
            {
                (*f)[1][j] = (*f)[1][j - 1] + a[1][j];
                (*l)[1][j] = 2;
            }
            else
            {
                (*f)[1][j] = (*f)[0][j - 1] + t[0][j - 1] + a[1][j];
                (*l)[1][j] = 1;
            }
        }
    }
    (*f)[0][n - 1] += x1;
    (*f)[1][n - 1] += x2;
    return (*f)[0][n - 1] <= (*f)[1][n - 1] ? (1) : (2);
}
int main()
{
    int e1 = 2, e2 = 4, x1 = 3, x2 = 6, n = 5;

    int k = Fastest_Way(&f, &l, e1, e2, x1, x2, n);
    for (int i = 0; i < n; i++)
    {
        cout << l[k - 1][i];
    }
    cout << endl
         << f[k - 1][n - 1];
    return 0;
}