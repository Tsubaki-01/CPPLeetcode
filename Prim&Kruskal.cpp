/*
题目描述：

在世界的某个区域，有一些分散的神秘岛屿，每个岛屿上都有一种珍稀的资源或者宝藏。国王打算在这些岛屿上建公路，方便运输。

不同岛屿之间，路途距离不同，国王希望你可以规划建公路的方案，如何可以以最短的总公路距离将所有岛屿联通起来。

给定一张地图，其中包括了所有的岛屿，以及它们之间的距离。以最小化公路建设长度，确保可以链接到所有岛屿。

输入描述：

第一行包含两个整数V 和 E，V代表顶点数，E代表边数 。顶点编号是从1到V。例如：V=2，一个有两个顶点，分别是1和2。

接下来共有 E 行，每行三个整数 v1，v2 和 val，v1 和 v2 为边的起点和终点，val代表边的权值。

输出描述：

输出联通所有岛屿的最小路径总距离

输入示例：

7 11
1 2 1
1 3 1
1 5 2
2 6 1
2 4 2
2 3 2
3 4 1
4 5 1
5 6 2
5 7 1
6 7 1
输出示例：

6
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  @brief Prim算法，用于求解最小生成树
 *
 *  时间复杂度O(n^2)，n为节点数量
 *
 *  @param graph 邻接矩阵，表示图的边权重，不可到达的边设置为INT_MAX
 *  @return pair<vector<int>, int> 返回生成树的父节点数组和总权重
 */
 // Prim算法，用于求解最小生成树
pair<vector<int>, int> Prim(vector<vector<int>>graph)
{
    // 获取图的顶点数
    int v = graph.size();
    // 初始化一个数组，用于记录每个顶点是否已经被选择
    vector<int> isInTree(v, 0);
    // 初始化一个数组，用于记录每个顶点到生成树的最小距离
    vector<int> minDistance(v, INT_MAX - 1);
    // 初始化一个数组，用于记录每个顶点的父节点
    vector<int> parent(v, -1);


    // 遍历v-1次，每次选择一个顶点加入生成树
    for (int i = 0;i < v - 1;i++)
    {
        // 初始化当前选择的顶点为-1
        int cur = -1;

        // 初始化当前最小距离为最大值
        int tempDis = INT_MAX;
        // 遍历所有顶点，找到未被选择且距离最小的顶点
        for (int j = 1;j < v;j++)
        {
            if (isInTree[j] == 0 && minDistance[j] < tempDis)
            {
                tempDis = minDistance[j];
                cur = j;
            }
        }
        // 将当前顶点标记为已选择
        isInTree[cur] = 1;

        // 遍历所有顶点，更新未被选择且距离更小的顶点的最小距离和父节点
        for (int j = 1;j < v;j++)
        {
            if (isInTree[j] == 0 && graph[cur][j] < minDistance[j])
            {
                minDistance[j] = graph[cur][j];
                parent[j] = cur;
            }
        }

    }
    // 返回生成树的父节点数组和总权重
    return pair<vector<int>, int>(parent, accumulate(minDistance.begin() + 2, minDistance.end(), 0));
}


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

// 定义边结构体
struct Edge
{
    int l; // 边的左端点
    int r; // 边的右端点
    int val; // 边的权重
    Edge(int _l, int _r, int _val) :l(_l), r(_r), val(_val) { }; // 构造函数
};

/**
 * @brief Kruskal 算法实现，用于计算最小生成树
 *
 * Kruskal 算法是一种用于计算加权无向图的最小生成树的算法。
 * 它通过贪心策略，每次选择权重最小的边，并确保不会形成环。
 *
 * @param graph 边的集合，每个边包含两个端点和一个权重
 * @param vertexSum 图中顶点的数量
 * @return pair<vector<Edge>, int> 第一个元素是最小生成树的边，第二个元素是最小生成树的权重
 */
 // Kruskal算法，用于求解最小生成树
pair<vector<Edge>, int> Kruskal(vector<Edge> graph, int vertexSum)
{
    pair<vector<Edge>, int> res; // 存储结果，第一个元素为最小生成树的边，第二个元素为最小生成树的权重

    DSU dsu(vertexSum); // 初始化并查集
    sort(graph.begin(), graph.end(), [] (Edge& a, Edge& b) { return a.val < b.val; }); // 按照边的权重从小到大排序

    for (int i = 0;i < vertexSum - 1;i++) // 遍历所有边
    {
        for (auto edge : graph) // 遍历所有边
        {
            if (!dsu.isSame(edge.l, edge.r)) // 如果边的两个端点不在同一个集合中
            {
                res.first.push_back(edge); // 将边加入最小生成树
                res.second += edge.val; // 更新最小生成树的权重
                dsu.join(edge.l, edge.r); // 将边的两个端点合并到同一个集合中
                break; // 继续遍历下一条边
            }
        }
    }
    return res; // 返回最小生成树
}





int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v + 1, vector<int>(v + 1, INT_MAX));
    vector<Edge> gra;
    while (e--)
    {
        int p1, p2, val;
        cin >> p1 >> p2 >> val;
        graph[p1][p2] = val;
        graph[p2][p1] = val;
        gra.emplace_back(p1, p2, val);
    }

    vector<int> parent = Prim(graph).first;
    cout << Prim(graph).second << endl;
    for (int i = 1; i <= v; i++)
    {
        cout << i << "->" << parent[i] << endl;
    }

    pair<vector<Edge>, int> res = Kruskal(gra, v + 1);
    cout << res.second << endl;
    for (Edge edge : res.first)
    {
        cout << edge.l << " - " << edge.r << " : " << edge.val << endl;
    }

    return 0;
}
