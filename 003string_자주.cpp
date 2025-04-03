/*
자주 사용하는 std::string 함수들
// 조회
length() / size(): 문자열의 길이를 반환합니다.
empty(): 문자열이 비어 있는지 확인합니다.
substr(): 문자열의 일부를 추출하여 반환합니다.
find(): 문자열 내에서 부분 문자열을 찾고 그 위치를 반환합니다.
compare(): 두 문자열을 비교합니다.
// 삽입
append(): 문자열의 끝에 문자열을 추가합니다.
insert(): 지정된 위치에 문자열을 삽입합니다.    // insert(pos, str), ex) insert(3, "abc") -> "Hello, world!" -> "Helabclo, world!"
// 삭제
erase(): 지정된 위치에서 문자열의 일부를 제거합니다.    // erase(pos, len), ex) erase(3, 5) -> "Hello, world!" -> "Hel, world!"
// 수정
replace(): 문자열의 일부를 다른 문자열로 교체합니다.    // replace(pos, len, str), len : length of the string to be replaced
// 기타
reverse(): 문자열을 뒤집습니다.   // reverse(str.begin(), str.end())
c_str(): 문자열의 C 스타일 표현을 반환합니다
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "Hello, world!";
    string str2 = "Hello, universe!";

    // length() / size()
    cout << "Length of str: " << str.length() << endl;

    // empty()
    string emptyStr;
    cout << "Is emptyStr empty? " << (emptyStr.empty() ? "Yes" : "No") << endl;

    // append()
    str.append(" How are you?");
    cout << "After append: " << str << endl;

    // insert()
    str.insert(13, " dear");
    cout << "After insert: " << str << endl; // "Hello, world! How are you?" -> "Hello, world! How are you? dear"

    // erase()
    str.erase(13, 5); // "dear " 제거
    cout << "After erase: " << str << endl;

    // replace()
    str.replace(7, 5, "Universe"); // "world" -> "Universe", prototype : replace(pos, len, str), len : length of the string to be replaced
    cout << "After replace: " << str << endl;

    // substr()
    string substr = str.substr(7, 8); // "Universe" 추출, prototype : substr(pos, len), len : length of the substring
    cout << "Substring: " << substr << endl;

    // find()
    size_t pos = str2.find("universe");
    if (pos != string::npos) // string::npos : string에서 찾지 못한 경우 반환되는 값,
        cout << "'universe' found at position " << pos << endl;
    else
        cout << "'universe' not found" << endl;

    // compare()
    cout << "Comparison between str and str2: " << str.compare(str2) << endl;

    // c_str()
    const char *cStyleStr = str.c_str();
    cout << "C-style string: " << cStyleStr << endl;

    return 0;
}
