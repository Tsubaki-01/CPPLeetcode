#include <bits/stdc++.h>
using namespace std;

void dfs(vector<list<int>>& graph, int cur, vector<int>& visited)
{
    if (visited[cur] == 1)
    {
        return;
    }

    for (auto p : graph[cur])
    {
        visited[p] = 1;
        dfs(graph, p, visited);
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<list<int>> graph(n - 1);
    while (m--)
    {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }
    vector<int> visited(n + 1, 0);
    visited[1] = 1;

    dfs(graph, 1, visited);

    accumulate(visited.begin(), visited.end(), 0) == n ? cout << 1 : cout << -1;
    return 0;
}

