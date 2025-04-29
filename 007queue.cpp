#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 기본 queue 사용법 예제
void basicQueueUsage()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "[기본 큐 사용]" << endl;
    cout << "Front: " << q.front() << endl; // 1
    cout << "Back: " << q.back() << endl;   // 3

    q.pop();                                          // 1 제거
    cout << "Front after pop: " << q.front() << endl; // 2

    cout << "Size: " << q.size() << endl;
    cout << "Empty? " << (q.empty() ? "Yes" : "No") << endl;
}

// BFS 예제 (그래프 탐색)
void bfsExample()
{
    cout << "[BFS 예제]" << endl;

    // 인접 리스트 기반 그래프 (1부터 시작)
    vector<vector<int>> graph = {
        {},     // 0 (사용 안 함)
        {2, 3}, // 1번 노드 → 2, 3
        {4},    // 2번 노드 → 4
        {},     // 3
        {}      // 4
    };

    vector<bool> visited(5, false);
    queue<int> q;

    int start = 1;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int next : graph[cur])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    cout << endl;
}

// 시뮬레이션 예제: 입장 순서대로 처리
void processQueueExample()
{
    cout << "[시뮬레이션 - 순서 처리]" << endl;

    queue<string> line;
    line.push("Alice");
    line.push("Bob");
    line.push("Charlie");

    while (!line.empty())
    {
        cout << line.front() << " served!" << endl;
        line.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    basicQueueUsage();
    cout << "------------------------" << endl;

    bfsExample();
    cout << "------------------------" << endl;

    processQueueExample();
    cout << "------------------------" << endl;

    return 0;
}
