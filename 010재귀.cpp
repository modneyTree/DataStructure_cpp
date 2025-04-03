// 재귀(Recursion)란?
// 함수가 자기 자신을 다시 호출하는 것

// 작은 문제로 쪼개서 푸는 방식 (Divide and Conquer)

// **탈출 조건 (기저 조건)**이 반드시 필요

// 기본구조
void recursion(int n) {
    if (n == 0) return; // 기저 조건
    // 수행할 작업
    recursion(n - 1);   // 자기 자신 호출 (작은 문제로 줄어듦)
}


// 예1 팩토리얼
int factorial(int n) {
    if (n == 0) return 1;  // 기저 조건
    return n * factorial(n - 1);  // 재귀 호출
}

// 예2 피보나치수열
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

