/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 *
 * https://leetcode.cn/problems/rotate-image/description/
 *
 * algorithms
 * Medium (76.67%)
 * Likes:    1928
 * Dislikes: 0
 * Total Accepted:    630.6K
 * Total Submissions: 820.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 *
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[7,4,1],[8,5,2],[9,6,3]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 *
 *
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int times = (n + 1) / 2;

        vector<vector<int>> pos;
        pos.push_back({ 0,0 });
        pos.push_back({ 0,n - 1 });
        pos.push_back({ n - 1,n - 1 });
        pos.push_back({ n - 1,0 });
        vector<vector<int>> directions;
        directions.push_back({ 0,1 });
        directions.push_back({ 1,0 });
        directions.push_back({ 0,-1 });
        directions.push_back({ -1,0 });

        for (int i = 0; i < times; i++)
        {
            auto pos_copy = pos;
            for (int j = n - 2 - 2 * i; j >= 0; j--)
            {
                swap(matrix[pos_copy[1][0]][pos_copy[1][1]], matrix[pos_copy[0][0]][pos_copy[0][1]]);
                swap(matrix[pos_copy[0][0]][pos_copy[0][1]], matrix[pos_copy[3][0]][pos_copy[3][1]]);
                swap(matrix[pos_copy[3][0]][pos_copy[3][1]], matrix[pos_copy[2][0]][pos_copy[2][1]]);
                for (int k = 0; k < 4; k++)
                {
                    pos_copy[k][0] += directions[k][0];
                    pos_copy[k][1] += directions[k][1];
                }
            }
            pos[0][0]++;
            pos[0][1]++;
            pos[1][0]++;
            pos[1][1]--;
            pos[2][0]--;
            pos[2][1]--;
            pos[3][0]--;
            pos[3][1]++;
        }

    }
};
// @lc code=end

