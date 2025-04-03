#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  stack<int> S;
  S.push(10);               // 10
  S.push(20);               // 10 20
  S.push(30);               // 10 20 30
  cout << S.size() << '\n'; // 3
  if (S.empty())
    cout << "S is empty\n";
  else
    cout << "S is not empty\n"; // S is not empty
  S.pop();                      // 10 20
  cout << S.top() << '\n';      // 20
  S.pop();                      // 10
  cout << S.top() << '\n';      // 10
  S.pop();                      // empty
  if (S.empty())
    cout << "S is empty\n"; // S is empty
  // cout << S.top() << '\n';  // runtime error 발생 --> segmentation fault

  // stack을 이용한 반전 출력
  for (int i = 0; i < 5; i++)
    S.push(i);

  while (!S.empty())
  {
    cout << S.top() << ' ';
    S.pop();
  }
}

void stack_example()
{
  // 스택 선언
  stack<int> S;
  stack<int> S2(S);         // S를 복사한 S2 생성
  stack<int> S3({1, 2, 3}); // 초기화 리스트를 이용한 스택 생성

  // 삽입 연산
  S.push(10);

  // 삭제 연산
  S.pop();

  // 정보 가져오기
  S.size();
  S.top();   // 스택의 맨 위 원소 반환
  S.empty(); // 스택이 비어있으면 true, 아니면 false 반환

  // 기타
  S.swap(S2);        // S와 S2의 원소를 서로 바꿈, 전부 복사되므로 시간복잡도 O(N)
  S = S2;            // S2의 원소를 S에 복사
  S2 = stack<int>(); // S2를 비움

  // stack을 이용한 반전 출력
  for (int i = 0; i < 5; i++)
    S.push(i); // 0 1 2 3 4

  while (!S.empty())
  {
    cout << S.top() << ' '; // 4 3 2 1 0
    S.pop();
  }

  // stack을 이용한 문자열 뒤집기
  string str = "abcde";
  stack<char> S;
  for (char c : str)
    S.push(c);
}

void make_stack_with_array()
{
  // 배열을 이용한 스택 구현
  int stack[10000];
  int size = 0;

  // 삽입 연산
  stack[size++] = 10;

  // 삭제 연산
  size--;

  // 정보 가져오기
  stack[size - 1]; // 스택의 맨 위 원소 반환
  size == 0;       // 스택이 비어있으면 true, 아니면 false 반환
}

void make_stack_with_list()
{
  // 리스트를 이용한 스택 구현
  list<int> L;

  // 삽입 연산
  L.push_back(10);

  // 삭제 연산
  L.pop_back();

  // 정보 가져오기
  L.back();  // 스택의 맨 위 원소 반환
  L.empty(); // 스택이 비어있으면 true, 아니면 false 반환
}