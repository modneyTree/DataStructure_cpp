#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // ✅ Create (삽입)
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(1); // 중복 삽입 무시됨

    // ✅ Read (조회)
    if (s.count(3)) cout << "3 있음\n";
    if (s.find(10) == s.end()) cout << "10 없음\n";

    // ✅ Update (X) - set은 값을 직접 수정 ❌
    // 방법: 삭제 후 다시 삽입
    if (s.count(4)) {
        s.erase(4);      // 삭제
        s.insert(5);     // 새로운 값 삽입 (사실상 '수정')
    }

    // ✅ Delete (삭제)
    s.erase(1);  // 1 삭제

    // ✅ 전체 출력 (정렬됨)
    for (int x : s)
        cout << x << " ";
    cout << "\n";

    return 0;
}

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us;

    // ✅ Create (삽입)
    us.insert(10);
    us.insert(20);
    us.insert(10); // 중복 삽입 무시됨

    // ✅ Read (조회)
    if (us.count(20)) cout << "20 있음\n";
    if (us.find(5) == us.end()) cout << "5 없음\n";

    // ✅ Update (X) - 값 수정은 불가, 삭제 후 삽입
    if (us.count(10)) {
        us.erase(10);
        us.insert(99); // 10 → 99로 '수정'
    }

    // ✅ Delete (삭제)
    us.erase(20);

    // ✅ 전체 출력 (정렬 ❌, 순서 무작위)
    for (int x : us)
        cout << x << " ";
    cout << "\n";

    return 0;
}

// multiset
#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;

    // ✅ Create (삽입) - 중복 허용!
    ms.insert(10);
    ms.insert(20);
    ms.insert(10);
    ms.insert(20);

    // ✅ Read (조회) - count로 중복 개수 확인
    cout << "10의 개수: " << ms.count(10) << "\n"; // 2

    // ✅ Update (X) - 개별 원소 수정 불가 → erase + insert
    // 10 하나만 99로 바꾸기
    auto it = ms.find(10);
    if (it != ms.end()) {
        ms.erase(it);     // 10 하나만 제거 (전체 X!)
        ms.insert(99);    // 99 삽입 (사실상 수정)
    }

    // ✅ Delete (삭제)
    ms.erase(20); // 20 전부 삭제됨 (중복 포함)

    // ✅ 전체 출력 (정렬됨, 중복 유지)
    for (int x : ms)
        cout << x << " ";
    cout << "\n";

    return 0;
}

