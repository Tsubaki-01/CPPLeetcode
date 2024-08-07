// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem51.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include<iostream>
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> result;
    bool isValid(vector<vector<int>>& plate, int row, int col, int n)
    {
        for (int i = 0;i < row;i++)
        {
            if (plate[i][col] == 1)
                return false;
        }
        for (int i = 1;row - i >= 0 && (col + i < n || col - i >= 0);i++)
        {
            if ((row - i >= 0 && col - i >= 0) && plate[row - i][col - i] == 1)
                return false;
            if ((row - i >= 0 && col + i < n) && plate[row - i][col + i] == 1)
                return false;
        }
        return true;
    }
    void nQueen(int n, int row, vector<vector<int>>& plate)
    {
        if (row >= n)
        {
            vector<string> item(n, string(n, '.'));
            for (int i = 0;i < n;i++)
                for (int j = 0;j < n;j++)
                    if (plate[i][j] == 1)
                    {
                        item[i][j] = 'Q';
                        break;
                    }
            result.push_back(item);
        }

        for (int col = 0;col < n;col++)
        {
            if (isValid(plate, row, col, n))
                plate[row][col] = 1;
            else continue;
            nQueen(n, row + 1, plate);
            plate[row][col] = 0;
        }



    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> plate(n, vector<int>(n, 0));
        nQueen(n, 0, plate);
        return result;
    }
};
// @lc code=end

