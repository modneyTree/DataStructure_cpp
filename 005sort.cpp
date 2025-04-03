// sort() 함수 기본적인 사용법
// sort() 함수는 algorithm 헤더에 정의되어 있으며, 벡터를 정렬할 때 사용한다.
// sort() 함수는 기본적으로 오름차순으로 정렬한다.
// sort() 함수의 두 번째 인자로는 정렬 방법을 지정하는 함수 객체를 전달할 수 있다.

#include <iostream>
#include <vector>
#include <algorithm> // sort가 정의된 헤더

using namespace std;

void 기본적인_사용법()
{
    vector<int> v = {5, 3, 8, 1, 2};

    // 기본적인 오름차순 정렬
    sort(v.begin(), v.end());

    // 내림차순 정렬
    sort(v.begin(), v.end(), greater<int>());

    for (int n : v)
    {
        cout << n << " ";
    }
}

// 사용자 정의 함수
bool compare(int a, int b)
{
    return a > b; // 내림차순 비교
}
void 사용자_정의_함수_객체()
{
    vector<int> v = {5, 3, 8, 1, 2};

    // 내림차순 정렬
    sort(v.begin(), v.end(), compare);

    for (int n : v)
    {
        cout << n << " ";
    }
}

// 람다 함수를 사용한 사용자 정의 비교 함수
void 람다_함수_사용()
{
    vector<int> v = {5, 3, 8, 1, 2};

    // 람다 함수를 사용한 내림차순 정렬
    sort(v.begin(), v.end(), [](int a, int b)
         { return a > b; });

    for (int n : v)
    {
        cout << n << " ";
    }
}

// 문자열 벡터 정렬
void 문자열_벡터_정렬()
{
    vector<string> v = {"apple", "banana", "orange", "melon"};

    // 문자열 길이로 오름차순 정렬
    sort(v.begin(), v.end(), [](string a, string b)
         { return a.size() < b.size(); });

    for (string s : v)
    {
        cout << s << " ";
    }
}

void 사용자_문자열_벡터_정렬()
{
    vector<string> v = {"apple", "banana", "kiwi", "grape", "plum"};

    // 문자열을 길이와 사전순으로 정렬
    sort(v.begin(), v.end(), [](const string &a, const string &b)
         {
             if (a.size() == b.size())
             {
                 return a < b; // 길이가 같으면 사전순으로 정렬
             }
             return a.size() < b.size(); // 길이가 다르면 짧은 것부터 정렬
         });

    for (const string &s : v)
    {
        cout << s << " ";
    }
}
