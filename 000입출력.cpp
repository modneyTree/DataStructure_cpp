#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>  // setprecision
using namespace std;

// 빠른 입출력 설정
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fastIO(); // 입출력 속도 최적화

    // 1. 기본 입력/출력
    int a, b;
    cin >> a >> b;
    cout << "입력된 숫자: " << a << " " << b << "\n";

    // 2. 공백 포함 문자열 입력
    cin.ignore(); // 이전 cin 입력 버퍼 제거
    string line;
    getline(cin, line);
    cout << "문자열 입력: " << line << "\n";

    // 3. 한 줄에 여러 숫자 → 벡터에 저장
    cout << "공백으로 구분된 숫자들을 한 줄에 입력하세요:\n";
    getline(cin, line);
    stringstream ss(line);
    vector<int> v;
    int x;
    while (ss >> x) v.push_back(x);
    cout << "입력된 벡터: ";
    for (int num : v) cout << num << " ";
    cout << "\n";

    // 4. 소수점 출력 조절
    double pi = 3.1415926535;
    cout << fixed << setprecision(3);
    cout << "Pi 출력 (소수 3자리): " << pi << "\n";

    // 5. char → int, int → char
    char ch = '7';
    int n = ch - '0'; // '7' → 7
    cout << "char '7' → int: " << n << "\n";

    int num = 5;
    char c = num + '0'; // 5 → '5'
    cout << "int 5 → char: " << c << "\n";

    // 6. 여러 줄 테스트케이스 입력
    int T;
    cout << "테스트케이스 수 입력: ";
    cin >> T;
    while (T--) {
        int val;
        cin >> val;
        cout << "테스트케이스 값: " << val << "\n";
    }

    return 0;
}
