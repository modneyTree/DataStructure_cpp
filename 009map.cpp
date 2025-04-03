#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> mp;

    // ✅ 삽입
    mp["apple"] = 3;               // 없으면 삽입
    mp["apple"] += 2;              // 있으면 값 누적
    mp.insert({"banana", 1});      // insert 사용 가능

    // ✅ 조회
    cout << mp["apple"] << "\n";   // 5

    // ✅ 존재 여부 확인
    if (mp.count("banana")) cout << "banana exist\n";
    if (mp.find("banana") != mp.end()) cout << "banana find\n";

    // ✅ 삭제
    mp.erase("banana");

    // ✅ 전체 출력 (key 오름차순 정렬)
    for (auto& m : mp)
        cout << m.first<< " : " << m.second << "\n";

    return 0;
}

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> ump;

    // ✅ 삽입
    ump["apple"] = 3;
    ump["apple"] += 2;
    ump.insert({"banana", 1});

    // ✅ 조회
    cout << ump["apple"] << "\n";  // 5

    // ✅ 존재 확인
    if (ump.count("banana")) cout << "banana 있음\n";
    if (ump.find("banana") != ump.end()) cout << "banana 찾음\n";

    // ✅ 삭제
    ump.erase("banana");

    // ✅ 전체 순회 (순서 ❌ 없음 → 무작위 순서)
    for (auto& m : ump)
        cout << m.first << " : " << m.second << "\n";

    return 0;
}
