#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int V = 4;                  // 정점의 수
    vector<vector<int>> adj(V); // 그래프의 인접 리스트 표현

    // 간선 추가
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    queue<int> q;                   // BFS를 위한 큐
    vector<bool> visited(V, false); // 정점 방문 여부 저장
    int s = 2;                      // BFS를 시작할 정점

    // BFS 시작
    visited[s] = true; // 시작 정점을 방문 표시
    q.push(s);         // 시작 정점을 큐에 추가

    while (!q.empty())
    {
        int v = q.front(); // 큐의 맨 앞 정점을 가져옴
        cout << v << " ";  // 정점을 출력
        q.pop();           // 큐에서 정점을 제거

        // 현재 정점의 모든 인접한 정점을 확인
        for (int u : adj[v])
        {
            if (!visited[u])
            {                      // 인접한 정점이 방문되지 않았다면
                visited[u] = true; // 방문 표시
                q.push(u);         // 큐에 추가
            }
        }
    }

    return 0;
}
