/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode.cn/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (67.61%)
 * Likes:    1097
 * Dislikes: 0
 * Total Accepted:    418.3K
 * Total Submissions: 615.2K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：[[1,0,1],[0,0,0],[1,0,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个仅使用常量空间的解决方案吗？
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

// O(1) Space
// 标志位，其实为了这点空间这么写没什么必要。但是标志位的思想可以用到O(m+n)空间的算法里，这样还挺巧妙的
class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int flag_row_0 = 0;
        int flag_col_0 = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = matrix[i][0] = 0;
                    if (i == 0)
                        flag_row_0 = 1;
                    if (j == 0)
                        flag_col_0 = 1;
                }

            }
        }

        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == 0)
                for (int i = 0; i < matrix.size(); i++)
                    matrix[i][j] = 0;
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
                fill(matrix[i].begin(), matrix[i].end(), 0);
        }

        if (flag_row_0)
            fill(matrix[0].begin(), matrix[0].end(), 0);
        if (flag_col_0)
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
    }
};
// @lc code=end

/*

// O(m+n) Space
// TODO：标志位版本算法
class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        unordered_set<int> todo_rows;
        unordered_set<int> todo_cols;

        // TODO：这里还可以剪枝
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (matrix[i][j] == 0)
                {
                    todo_rows.insert(i);
                    todo_cols.insert(j);
                }

        for (auto& row : todo_rows)
        {
            fill(matrix[row].begin(), matrix[row].end(), 0);
        }
        for (auto& col : todo_cols)
        {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][col] = 0;
        }

    }
};
 */