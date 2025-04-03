/*

DP 핵심 조건 (2가지)
Overlapping Subproblems
Optimal Substructure

DP 구현 방식 2가지
Top-Down (재귀 + 메모이제이션)
Bottom-Up (반복문)

DP 자주 나오는 유형
피보나치 수열
배낭 문제 (Knapsack)
최장 증가 부분 수열
동전 거스름 문제
이동 경로 찾기

*/

// 예1 피보나치수열
#include <iostream>
using namespace std;

int dp[50];

int main() {
    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}

// 예제 2. 1로 만들기 (DP 최적화 문제 - 점화식 세우기 연습)
// 정수 n이 1이 될 때까지 연산 최소 횟수 구하기
// 가능한 연산: -1, /2, /3
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];

int main() {
    int n;
    cin >> n;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    cout << dp[n];
}

// 예제 3. 계단 오르기 (DP 기본 응용)
// 한 번에 1칸 or 2칸 올라갈 수 있음
// 총 n칸일 때 오르는 방법의 수 구하기 (피보나치랑 비슷)
#include <iostream>
using namespace std;

int dp[50];

int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}

// 예제 4. 2차원 DP - 이동 경로 최댓값 구하기
// (1,1)에서 (N,M)까지 우측, 아래로만 이동
// 경로 중 숫자 합이 최대가 되게 만들기
#include <iostream>
#include <algorithm>
using namespace std;

int map[101][101];
int dp[101][101];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= M; j++) 
            cin >> map[i][j];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
        }
    }
    cout << dp[N][M];
}

