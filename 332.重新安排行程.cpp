// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem332.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
 /* 我们化简本题题意：给定一个 nnn 个点 mmm 条边的图，要求从指定的顶点出发，经过所有的边恰好一次（可以理解为给定起点的「一笔画」问题），使得路径的字典序最小。

 这种「一笔画」问题与欧拉图或者半欧拉图有着紧密的联系，下面给出定义：

 通过图中所有边恰好一次且行遍所有顶点的通路称为欧拉通路；
 通过图中所有边恰好一次且行遍所有顶点的回路称为欧拉回路；
 具有欧拉回路的无向图称为欧拉图；
 具有欧拉通路但不具有欧拉回路的无向图称为半欧拉图。
 因为本题保证至少存在一种合理的路径，也就告诉了我们，这张图是一个欧拉图或者半欧拉图。我们只需要输出这条欧拉通路的路径即可。

 如果没有保证至少存在一种合理的路径，我们需要判别这张图是否是欧拉图或者半欧拉图，具体地：

 对于无向图 GGG，GGG 是欧拉图当且仅当 GGG 是连通的且没有奇度顶点。
 对于无向图 GGG，GGG 是半欧拉图当且仅当 GGG 是连通的且 GGG 中恰有 000 个或 222 个奇度顶点。
 对于有向图 GGG，GGG 是欧拉图当且仅当 GGG 的所有顶点属于同一个强连通分量且每个顶点的入度和出度相同。
 对于有向图 GGG，GGG 是半欧拉图当且仅当
 如果将 GGG 中的所有有向边退化为无向边时，那么 GGG 的所有顶点属于同一个强连通分量；
 最多只有一个顶点的出度与入度差为 111；
 最多只有一个顶点的入度与出度差为 111；
 所有其他顶点的入度和出度相同。
 */

 // 图的DFS
#include<iostream>
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include<map>

using namespace std;
// @lc code=start
class Solution {
private:
    vector<string> result;
    unordered_map<string, map<string, int>> from_to;

    bool backtracking(int size, string cur)
    {
        if (result.size() > size)
        {
            return true;
        }

        for (auto i : from_to[cur])
        {
            if (i.second > 0)
                result.push_back(i.first);
            else continue;
            i.second--;
            if (backtracking(size, i.first))
                return true; // 递归
            result.pop_back();
            i.second++;
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        result.clear();
        int size = tickets.size();
        for (auto i : tickets)
            from_to[i[0]][i[1]]++;
        // for (auto i : from_to)
        // {
        //     cout << i.first << endl;
        //     for (auto j : from_to[i.first])
        //         cout << j.first << j.second << endl;
        // }
        result.push_back("JFK");
        backtracking(size, "JFK");
        return result;
    }
};
// @lc code=end
/* class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;

    vector<string> stk;

    void dfs(const string& curr) {
        while (vec.count(curr) && vec[curr].size() > 0) {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(move(tmp));
        }
        stk.emplace_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& it : tickets) {
            vec[it[0]].emplace(it[1]);
        }
        dfs("JFK");

        reverse(stk.begin(), stk.end());
        return stk;
    }
};

作者：力扣官方题解
链接：https ://leetcode.cn/problems/reconstruct-itinerary/solutions/389885/zhong-xin-an-pai-xing-cheng-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */
