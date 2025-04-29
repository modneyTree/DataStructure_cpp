// 1번 문제
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>

#define endl '\n'

using namespace std;

// 함수 선언

// 전역 변수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 변수 선언, 초기화
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int k : v)
    {
        cout << k << " ";
    }
    cout << endl;

    // 로직
}

// 함수 정의

// 2번 문제
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>

#define endl '\n'

using namespace std;

// 함수 선언

// 전역 변수
bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 로직
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), compare);

    for (int k : v)
        cout << k << " ";
    cout << endl;
}

// 3번 문제
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>

#define endl '\n'

using namespace std;

// 함수 선언

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), [](string a, string b)
         {
        if (a.size() != b.size()) {
            return a.size() < b.size();
        } else {
            return a < b;
        } });

    for (string k : v)
        cout << k << " ";

    cout << endl;
}

// 함수 정의

// 4번 문제
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

#define endl "\n"

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

struct student
{
    string name;
    int nation;
    int english;
    int math;
};

void test()
{
    student st1 = {"isaac", 1, 2, 3};

    cout << st1.name << st1.nation << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<student> v;

    while (n--)
    {
        student st;
        cin >> st.name >> st.nation >> st.english >> st.math;

        v.push_back(st);
    }

    sort(v.begin(), v.end(), [](student s1, student s2)
         {
             if (s1.nation != s2.nation)
                 return s1.nation > s2.nation;
             else
             { // 국어 성적이 같은 경우
                 if (s1.english != s2.english)
                     return s1.english < s2.english;
                 else
                 { // 영어 성적 같은 경우
                     if (s1.math != s2.math)
                     {
                         return s1.math > s2.math;
                     }
                     else
                     { // 수학성적 같으면
                         return s1.name < s2.name;
                     }
                 }
             } });

    // print
    for (auto k : v)
        cout << k.name << endl;
}
