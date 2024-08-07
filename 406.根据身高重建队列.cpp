/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        else return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        for (auto i : people)
            cout << i[0] << i[1] << endl;
        list<vector<int>> result;
        for (auto item : people)
        {
            auto it = result.begin();
            for (int i = item[1];i > 0;i--)
                it++;
            result.insert(it, item);
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};
// @lc code=end

