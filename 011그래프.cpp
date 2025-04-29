#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;
vector<vector<int>> graph(MAX);
vector<bool> visited_dfs(MAX, false);
vector<bool> visited_bfs(MAX, false);

// DFS (재귀)
void dfs(int v)
{
    visited_dfs[v] = true;
    cout << v << " ";

    for (int u : graph[v])
    {
        if (!visited_dfs[u])
            dfs(u);
    }
}

// BFS (큐)
void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited_bfs[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int next : graph[cur])
        {
            if (!visited_bfs[next])
            {
                visited_bfs[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    예제 그래프:
    1 - 2
    |   |
    3 - 4
    */

    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(1);
    graph[2].push_back(4);
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[4].push_back(2);
    graph[4].push_back(3);

    int start = 1;

    cout << "[DFS 탐색 결과] ";
    dfs(start);
    cout << "\n";

    cout << "[BFS 탐색 결과] ";
    bfs(start);
    cout << "\n";

    return 0;
}
