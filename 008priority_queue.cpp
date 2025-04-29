#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// ✅ 기본 최대 힙 (default)
void maxHeapExample() {
    priority_queue<int> pq;

    pq.push(10);
    pq.push(5);
    pq.push(8);

    cout << "[최대 힙 예제]" << endl;
    while (!pq.empty()) {
        cout << pq.top() << " "; // 10 8 5
        pq.pop();
    }
    cout << endl;
}

// ✅ 최소 힙 (greater 사용)
void minHeapExample() {
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10);
    pq.push(5);
    pq.push(8);

    cout << "[최소 힙 예제]" << endl;
    while (!pq.empty()) {
        cout << pq.top() << " "; // 5 8 10
        pq.pop();
    }
    cout << endl;
}

// ✅ 사용자 정의 구조체 비교 (pair.second 기준 오름차순)
struct CompareSecond {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

void customCompareExample() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareSecond> pq;
    pq.push({1, 30});
    pq.push({2, 10});
    pq.push({3, 20});

    cout << "[사용자 정의 정렬 예제 (second 기준)]" << endl;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

// ✅ 실전: 작은 수부터 꺼내기 (숫자 정렬)
void processSmallestFirst() {
    vector<int> nums = {9, 1, 6, 3, 5};
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : nums) pq.push(x);

    cout << "[작은 수부터 정렬된 출력]" << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

// ✅ 람다를 이용한 우선순위 큐 예제 (pair.second 기준 오름차순)
void lambdaCompareExample() {
    auto cmp = [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second; // second 기준 오름차순
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    pq.push({1, 30});
    pq.push({2, 10});
    pq.push({3, 20});

    cout << "[람다 정렬 예제 (second 기준)]" << endl;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    maxHeapExample();
    cout << "------------------------" << endl;

    minHeapExample();
    cout << "------------------------" << endl;

    customCompareExample();
    cout << "------------------------" << endl;

    processSmallestFirst();
    cout << "------------------------" << endl;

    lambdaCompareExample();
    cout << "------------------------" << endl;

    return 0;
}
