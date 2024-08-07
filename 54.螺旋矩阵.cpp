/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

 // @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int di = 0;
        int dj = 1;
        int i = 0;
        int j = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(m * n, 0);
        int cnt = 0;
        int loop = 0;

        while (cnt < m * n) {
            res[cnt] = matrix[i][j];
            if (i + di == loop && j + dj == loop) {
                loop++;
            }
            if (i + di >= m - loop || i + di < loop || j + dj < loop ||
                j + dj >= n - loop) {
                int t = dj;
                dj = -di;
                di = t;
            }
            i = i + di;
            j = j + dj;
            cnt++;
        }
        return res;
    }
};
// @lc code=end

