/*
길이 구하기	    s.size(), s.length()
문자 접근	    s[i], s.at(i)
뒤집기	        reverse(s.begin(), s.end())
비교	        s == t, s.compare(t)
부분 문자열	     s.substr(pos, len)
찾기	        s.find(t), s.rfind(t)
대체	        s.replace(pos, len, newStr)
삽입	        s.insert(pos, newStr)
삭제	        s.erase(pos, len), erase-remove
정렬	        sort(s.begin(), s.end())
대소문자 변환	toupper(), tolower()
숫자 변환	    stoi(s), to_string(n)
문자열 분할	    stringstream
*/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

void string_operations()
{
    string s = "Hello, World!";
    cout << "Original: " << s << endl;

    // 길이 확인
    cout << "Length: " << s.size() << endl;

    // 문자열 뒤집기
    reverse(s.begin(), s.end());
    cout << "Reversed: " << s << endl;

    // 부분 문자열
    cout << "Substring: " << s.substr(0, 5) << endl;

    // 찾기
    cout << "Find 'World': " << (s.find("World") != string::npos ? "Found" : "Not found") << endl;

    // 문자열 변경
    s.replace(0, 5, "Hey");
    cout << "Replaced: " << s << endl;

    // 문자열 삽입
    s.insert(3, ", Hi");
    cout << "Inserted: " << s << endl;

    // 문자열 삭제
    s.erase(3, 4);
    cout << "Erased: " << s << endl;

    // 공백 제거 (erase-remove)
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    cout << "Without spaces: " << s << endl;

    // 대소문자 변환
    for (char &c : s)
        c = tolower(c);
    cout << "Lowercase: " << s << endl;

    for (char &c : s)
        c = toupper(c);
    cout << "Uppercase: " << s << endl;

    // 문자열 정렬
    sort(s.begin(), s.end());
    cout << "Sorted: " << s << endl;

    // 숫자 변환
    int num = stoi("123");
    cout << "String to Int: " << num + 10 << endl;
    cout << "Int to String: " << to_string(456) + "7" << endl;

    // 문자열 분할
    string words = "apple orange banana";
    stringstream ss(words);
    string word;
    while (ss >> word)
        cout << "Word: " << word << endl;
}

int main()
{
    string_operations();
    return 0;
}
