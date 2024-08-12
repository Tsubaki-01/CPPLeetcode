// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem685.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 *
 * https://leetcode.cn/problems/redundant-connection-ii/description/
 *
 * algorithms
 * Hard (42.22%)
 * Likes:    412
 * Dislikes: 0
 * Total Accepted:    37.5K
 * Total Submissions: 88.9K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 在本问题中，有根树指满足以下条件的 有向
 * 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。
 *
 * 输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n
 * 中的两个不同顶点间，这条附加的边不属于树中已存在的边。
 *
 * 结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是
 * vi 的一个父节点。
 *
 * 返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：edges = [[1,2],[1,3],[2,3]]
 * 输出：[2,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
 * 输出：[4,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ui, vi <= n
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
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

    bool isATreeAfterRemove(vector<vector<int>>& edges, int in, int out)
    {
        DSU dsu(edges.size() + 1);
        for (auto edge : edges)
        {
            if (edge[0] == in && edge[1] == out)
                continue;

            if (dsu.isSame(edge[0], edge[1]))
                return false;

            dsu.join(edge[0], edge[1]);
        }
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
    {
        vector<int> inDegree(edges.size() + 1, 0);
        vector<vector<int>> in(edges.size() + 1);
        vector<vector<int>> out(edges.size() + 1);
        for (auto edge : edges)
        {
            out[edge[0]].push_back(edge[1]);
            in[edge[1]].push_back(edge[0]);
            inDegree[edge[1]] += 1;
        }

        // 寻找入度为二的节点
        auto it = find_if(inDegree.begin(), inDegree.end(), [] (int v) { return v == 2; });

        if (it != inDegree.end())
        {
            int pos = distance(inDegree.begin(), it);
            reverse(in[pos].begin(), in[pos].end());
            for (auto v : in[pos])
            {
                // 这题前提是这个图原本就是棵树，所以能使用并查集
                if (isATreeAfterRemove(edges, v, pos))
                    return vector<int>{ v, pos};
            }
        }
        else
        {
            // 没有入度为二的节点，说明不存在根节点，一定存在有向环，之后检查哪条边使得成环
            // 这题前提是已经没有入度为二的节点了，所以在有向图里能用并查集
            DSU dsu(edges.size() + 1);
            for (auto edge : edges)
            {
                if (!dsu.isSame(edge[0], edge[1]))
                    dsu.join(edge[0], edge[1]);
                else return edge;
            }
        }
        return vector<int>{};
    }
};
// @lc code=end

