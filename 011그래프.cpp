/*
// 인접리스트 기준 그래프 이론 정리

// 기본형태
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[101]; // 인접 리스트 (노드 번호 1부터 100까지)

// 간선 추가 (무방향 그래프 예시)
graph[1].push_back(2);
graph[2].push_back(1);

// DFS
void dfs(int node) {
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) dfs(next);
    }
}

// BFS
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int next : graph[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

// 가중치가 있는 그래프
vector<pair<int, int>> graph[101]; // pair<목적지, 가중치>
graph[1].push_back({2, 5}); // 1에서 2로 가는 가중치 5

*/

// 예제
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;
vector<int> graph[MAX];
bool visited[MAX];

// DFS 구현 (재귀)
void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

// BFS 구현 (큐)
void bfs(int start) {
    queue<int> q;
    fill(visited, visited + MAX, false); // 방문 배열 초기화

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int next : graph[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;  // 정점 개수, 간선 개수, 시작점

    // 간선 입력 받기 (무방향 그래프)
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 작은 번호부터 탐색하기 위해 정렬 (코테에서 자주 요구)
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS 실행
    dfs(start);
    cout << '\n';

    // BFS 실행
    bfs(start);
    cout << '\n';

    return 0;
}

