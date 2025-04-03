#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define endl '\n' // 코테용 추천

using namespace std;

// 전역변수

// 함수

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;

    cin >> n;
    cin >> s;

    cout << "helo world" << endl;
    cout << n << endl;
    cout << s << endl;
}

/*
<algorithm> 헤더는 C++ 표준 라이브러리에서 제공하는 알고리즘 관련 함수들을 모아둔 헤더입니다. 이 헤더에 포함된 함수들은 배열이나 벡터, 리스트와 같은 컨테이너뿐만 아니라 임의의 반복자(iterator)를 지원하는 시퀀스에 대해 범용적으로 작동하도록 설계되어 있습니다.

주요 특징 및 기능은 다음과 같습니다:

일반화된 알고리즘 제공:
템플릿 기반으로 구현되어 있어, 컨테이너의 종류와 상관없이 동일한 알고리즘을 사용할 수 있습니다.

정렬 및 검색 기능:

std::sort: 시퀀스 내 요소들을 오름차순(혹은 사용자 정의 기준에 따라) 정렬합니다.
std::binary_search: 정렬된 시퀀스에서 이진 검색을 수행하여 특정 값의 존재 여부를 확인합니다.
std::find, std::find_if: 시퀀스 내에서 원하는 값을 찾거나 조건에 맞는 첫 번째 요소를 찾습니다.
변환 및 복사 기능:

std::copy, std::copy_if: 시퀀스의 요소들을 다른 컨테이너나 위치로 복사합니다.
std::transform: 시퀀스의 각 요소에 함수를 적용하여 새로운 시퀀스를 생성합니다.
계산 및 통계 기능:

std::count, std::count_if: 시퀀스 내에서 특정 값이나 조건에 맞는 요소의 개수를 셉니다.
std::min_element, std::max_element: 시퀀스 내에서 최소값 또는 최대값을 가진 요소를 찾습니다.
수정 및 제거 기능:

std::remove, std::remove_if: 특정 값이나 조건에 맞는 요소들을 논리적으로 제거합니다.
std::reverse, std::reverse_copy: 시퀀스의 순서를 반전합니다.
이처럼 <algorithm> 헤더를 사용하면 복잡한 데이터 처리를 직접 구현할 필요 없이, 검증된 표준 알고리즘을 간편하게 활용할 수 있어 코드의 가독성과 효율성이 크게 향상됩니다.

<cmath>
수학 함수 제공:
제곱근(sqrt), 거듭제곱(pow), 삼각 함수(sin, cos, tan), 로그 함수(log, log10), 절대값(abs) 등 수학 계산에 필요한 함수들을 제공합니다.

C와의 호환성:
<cmath>는 C의 <math.h> 헤더를 C++ 스타일로 변환한 것으로, 네임스페이스 std 안에 함수들이 정의되어 있습니다. 따라서 C++에서는 std::sqrt, std::sin 등과 같이 사용합니다.

정확성과 성능:
대부분의 함수들은 컴파일러나 표준 라이브러리에 의해 최적화되어 있어, 수학 연산을 빠르고 정확하게 수행할 수 있습니다.
*/