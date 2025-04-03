#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N = 10;
    // 선언
    vector<int> A; // 1차원 벡터 선언, 괄호 없음

    // 초기화
    vector<int> B(5);    // 0으로 초기화된 5개의 원소를 가진 벡터
    vector<int> C(5, 1); // 1로 초기화된 5개의 원소를 가진 벡터
    A.resize(5);         // 0으로 초기화된 5개의 원소를 가진 벡터

    // Index : iterator 사용
    auto it = A.begin();
    distance(A.begin(), it); // A.begin()부터 it까지의 거리 반환(== 인덱스와 동일)

    // I : 삽입 연산
    A.push_back(1);

    // U : 값 변경
    A[4] = -5;

    // D : 삭제 연산
    A.pop_back();
    A.erase(A.begin() + 1);            // 인덱스 1의 원소(20) 삭제
    A.erase(A.begin(), A.begin() + 2); // 인덱스 0, 1 삭제

    // Q : 정보 가져오기
    A.empty();
    A.size();
    A.front();
    A.back();
    A[3];

    // 탐색 전역함수들(Global Functions)
    find(A.begin(), A.end(), 3);     // 찾는 값의 이터레이터 반환 : A.end()의 이터레이터 반환,
    count(A.begin(), A.end(), 3);    // 찾는 값의 개수 반환
    min_element(A.begin(), A.end()); // 반환값   포인터
    max_element(A.begin(), A.end()); // 반환값   포인터

    // 기타 전역함수들(Global Functions)
    fill(A.begin(), A.end(), false);
    sort(A.begin(), A.end());
    reverse(A.begin(), A.begin());
    copy(A.begin(), A.end(), B.begin());
    swap(A, B);
    remove(A.begin(), A.end(), 10);                   // 10을 삭제, 실제로 삭제되지 않음, 삭제된 원소는 뒤로 이동
    A.erase(remove(A.begin(), A.end(), 10), A.end()); // 삭제된 원소를 벡터에서 제거

    // 출력
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }

    for (int i : A)
    {
        cout << i << " ";
    }
}

int 이차원_벡터()
{
    // n x n 행렬
    int N;
    cin >> N;

    // 2차원 벡터 선언 및 초기화
    vector<vector<int>> A(N, vector<int>(N, 0));

    // 요소 추가
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j]; // 데이터 저장

    A[0][0] = 1; // (1, 1)에 1 저장

    A.push_back(vector<int>(N, 0)); // 행 추가

    // 요소 삭제
    A.pop_back(); // 마지막 행 삭제

    // 요소 출력
    cout << A[0][0] << "\n"; // (1, 1) 출력

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }

    for (const auto &row : A) // 범위 기반 for문, row는 벡터, A는 벡터의 벡터, A의 각 행을 순회, row는 A의 각 행, auto
    {
        for (const auto &elem : row)
            cout << elem << " ";
    }
}