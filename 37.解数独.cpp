// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem37.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
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
    vector<vector<char>> result;

    bool isValid(vector<vector<char>>& board, int row, int col)
    {
        char c = board[row][col];
        // 行
        for (int i = 0;i < 9;i++)
        {
            if (board[row][i] == c && i != col)
                return false;
        }
        // 列
        for (int i = 0;i < 9;i++)
        {
            if (board[i][col] == c && i != row)
                return false;
        }
        // 9X9
        int beginRow = row / 3;
        int beginCol = col / 3;
        for (int i = beginRow * 3;i < beginRow * 3 + 3;i++)
            for (int j = beginCol * 3;j < beginCol * 3 + 3;j++)
                if (i == row && j == col)
                    continue;
                else if (board[i][j] == c)
                    return false;
        return true;

    }
    /*
        关键是找到下一个空位进行回溯递归
     */
    bool backtracking(int row, int col, vector<vector<char>>& board)
    {
        if (row >= 9)
            return true;

        if (col >= 9)
            return backtracking(row + 1, 0, board);

        if (board[row][col] != '.')
            return backtracking(row, col + 1, board);

        for (char c = '1';c <= '9';c++)
        {
            board[row][col] = c;
            if (isValid(board, row, col))
                if (backtracking(row, col + 1, board))
                    return true;
            board[row][col] = '.';
        }
        return false;

    }

    void solveSudoku(vector<vector<char>>& board) {
        backtracking(0, 0, board);
        cout << backtracking(0, 0, board) << endl;
        cout << 1;
    }
};
// @lc code=end
