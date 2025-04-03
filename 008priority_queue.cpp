/*
우선순위 큐 (Priority Queue) 정리
std::priority_queue는 C++ 표준 라이브러리에서 제공하는 컨테이너 어댑터로, 요소들이 우선순위에 따라 정렬되는 자료구조입니다. 우선순위 큐는 주로 힙(Heap)을 기반으로 구현되며, 가장 큰(혹은 가장 작은) 요소를 빠르게 접근할 수 있도록 합니다.

기본 개념
우선순위 큐는 특정 우선순위에 따라 요소를 관리합니다.
최대 힙(Max-Heap): 가장 큰 요소가 항상 큐의 맨 위에 위치.
최소 힙(Min-Heap): 가장 작은 요소가 항상 큐의 맨 위에 위치.
기본적으로 std::priority_queue는 최대 힙으로 동작합니다.
멤버 함수
생성자

기본 생성자: std::priority_queue<T> pq;
다른 컨테이너를 기반으로 생성: std::priority_queue<T, Container> pq(container);
용량 관련 함수

empty(): 큐가 비어 있는지 확인합니다. 비어 있으면 true, 그렇지 않으면 false를 반환합니다.
size(): 큐에 있는 요소의 개수를 반환합니다.
요소 접근

top(): 큐의 맨 위 요소를 반환합니다. 이 요소는 최대 힙의 경우 가장 큰 요소, 최소 힙의 경우 가장 작은 요소입니다.
수정자

push(const T& value): 새로운 요소를 큐에 추가합니다.
emplace(Args&&... args): 요소를 직접 생성하여 큐에 추가합니다.
pop(): 큐의 맨 위 요소를 제거합니다.
swap(priority_queue& other): 다른 우선순위 큐와 내용을 교환합니다.

// pair를 이용한 우선순위 큐
// pair를 이용하여 우선순위 큐를 사용할 때는 pair의 첫 번째 원소를 기준으로 우선순위 큐가 정렬된다.
// pair의 첫 번째 원소가 같은 경우 두 번째 원소를 기준으로 정렬된다.
// pair의 첫 번째 원소가 큰 순서대로 정렬되므로 최소 힙을 이용하여 우선순위 큐를 구현할 수 있다.
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

// pair를 이용한 우선순위 큐 사용 예제
*/

// 기본 최대 힙 예제
#include <iostream>
#include <queue>

int main()
{
    // 기본 최대 힙 우선 순위 큐 선언
    std::priority_queue<int> pq;

    // 우선 순위 큐에 요소 추가
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    // 요소 접근 및 제거
    std::cout << "우선 순위 큐 요소 (최대 힙):" << std::endl;
    while (!pq.empty())
    {
        std::cout << pq.top() << " "; // 맨 위 요소에 접근
        pq.pop();                     // 맨 위 요소 제거
    }
    std::cout << std::endl;

    return 0;
}

// 사용자 정의 비교 함수 예제 (최소 힙)
#include <iostream>
#include <queue>
#include <vector>

int main()
{
    // 최소 힙 우선 순위 큐 선언
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;

    // 우선 순위 큐에 요소 추가
    min_pq.push(10);
    min_pq.push(30);
    min_pq.push(20);
    min_pq.push(5);

    // 요소 접근 및 제거
    std::cout << "우선 순위 큐 요소 (최소 힙):" << std::endl;
    while (!min_pq.empty())
    {
        std::cout << min_pq.top() << " "; // 맨 위 요소에 접근
        min_pq.pop();                     // 맨 위 요소 제거
    }
    std::cout << std::endl;

    return 0;
}

// 사용자 정의 비교 함수 예제
#include <iostream>
#include <queue>
#include <vector>

struct CustomCompare
{
    bool operator()(const int &lhs, const int &rhs)
    {
        return lhs > rhs; // lhs가 rhs보다 클 때 true를 반환하면 최소 힙이 됩니다.
    }
};

int main()
{
    // 사용자 정의 비교 함수를 사용하는 우선 순위 큐 선언
    std::priority_queue<int, std::vector<int>, CustomCompare> custom_pq;

    // 우선 순위 큐에 요소 추가
    custom_pq.push(10);
    custom_pq.push(30);
    custom_pq.push(20);
    custom_pq.push(5);

    // 요소 접근 및 제거
    std::cout << "우선 순위 큐 요소 (사용자 정의 비교 함수):" << std::endl;
    while (!custom_pq.empty())
    {
        std::cout << custom_pq.top() << " "; // 맨 위 요소에 접근
        custom_pq.pop();                     // 맨 위 요소 제거
    }
    std::cout << std::endl;

    return 0;
}
