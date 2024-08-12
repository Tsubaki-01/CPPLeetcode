/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 *
 * https://leetcode.cn/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (68.03%)
 * Likes:    639
 * Dislikes: 0
 * Total Accepted:    119.7K
 * Total Submissions: 175.9K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 树可以看成是一个连通且 无环 的 无向 图。
 *
 * 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n
 * 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai
 * 和 bi 之间存在一条边。
 *
 * 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的那个。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: edges = [[1,2], [1,3], [2,3]]
 * 输出: [2,3]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
 * 输出: [1,4]
 *
 *
 *
 *
 * 提示:
 *
 *
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ai < bi <= edges.length
 * ai != bi
 * edges 中无重复元素
 * 给定的图是连通的 
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class DSU
{
private:
    vector<int> father;
public:
    DSU(int n)
    {
        init(n);
    };
    DSU() { };
    ~DSU() = default;

    // 并查集初始化
    void init(int n)
    {
        father.resize(n);
        for (int i = 0; i < n; ++i)
        {
            father[i] = i;
        }
    }

    // 并查集里寻根的过程
    int find(int u)
    {
        return u == father[u] ? u : father[u] = find(father[u]); // 路径压缩
    }

    // 判断 u 和 v是否找到同一个根
    bool isSame(int u, int v)
    {
        int uRoot = find(u);
        int vRoot = find(v);
        return uRoot == vRoot;
    }

    // 将v->u 这条边加入并查集
    void join(int parent, int child)
    {
        int parentRoot = find(parent); // 寻找u的根
        int childRoot = find(child); // 寻找v的根
        if (parentRoot == childRoot) return; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
        father[childRoot] = parentRoot;
    }
};

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        DSU dsu(edges.size() + 1);
        for (auto edge : edges)
        {
            if (dsu.isSame(edge[0], edge[1]))
                return edge;
            dsu.join(edge[0], edge[1]);
        }
        return vector<int>();
    }
};
// @lc code=end

