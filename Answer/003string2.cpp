// 1번
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>

#define endl "\n"

using namespace std;

// 대문자 -> 소문자
string fun_lower(string s)
{
    for (char &ch : s)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + 32;
        }
    }

    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    stringstream ss(s);
    map<string, int> mp;
    int max_num = 0;
    string max_str;

    while (ss >> s)
    {
        // 문자열 전처리리
        // 대문자 -> 소문자
        s = fun_lower(s);

        // "." 지우기
        if (!s.empty() && s[s.size() - 1] == '.')
            s = s.substr(0, s.size() - 1);

        mp[s]++;

        // max 갱신
        if (mp[s] > max_num)
        {
            max_num = mp[s];
            max_str = s;
        }
    }

    cout << max_str << " " << max_num << endl;

    // for (auto &k : mp)
    //     cout << k.first << " " << k.second << endl;
}

// 2번
#include <iostream>
#include <string>
using namespace std;

// 문자열 반복 함수
string repeatStr(const string &s, int n)
{
    string res;
    for (int i = 0; i < n; i++)
        res += s;
    return res;
}

// 괄호 압축 해제 함수
string func2(string s)
{
    while (true)
    {
        // 가장 안쪽 '(' 위치 찾기
        size_t right = s.find(')');
        if (right == string::npos)
            break; // 괄호가 없으면 종료

        // 오른쪽에서부터 왼쪽 방향으로 '(' 찾기
        size_t left = right;
        while (left >= 0 && s[left] != '(')
            --left;

        // 괄호 안 문자열 추출
        string inside = s.substr(left + 1, right - left - 1);

        // 반복 횟수 추출 (한 자리 수 또는 여러 자리 수)
        size_t numStart = left - 1;
        while (numStart >= 0 && isdigit(s[numStart]))
        {
            if (numStart == 0)
                break;
            --numStart;
        }
        if (!isdigit(s[numStart]))
            numStart++; // 숫자 시작점 보정

        int repeat = stoi(s.substr(numStart, left - numStart));
        string expanded = repeatStr(func2(inside), repeat);

        // 전체 "n(...)" 구간 교체
        s.replace(numStart, right - numStart + 1, expanded);
    }

    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << func2("3(ab)") << endl;     // ababab
    cout << func2("2(a2(b))") << endl;  // abbabb
    cout << func2("2(a3(cd))") << endl; // acdcdcdacdcdcd
    cout << func2("10(x)") << endl;     // xxxxxxxxxx
}

// 2번
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
// #include <cctype>

#define endl "\n"

using namespace std;

// 괄호푸는 함수 func_patrnthe()
string func_parenthe(string s, int n)
{
    string res;
    for (int i = 0; i < n; i++)
    {
        res.append(s);
    }

    return res;
}

int test()
{
    cout << func_parenthe("abc", 3) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    // 괄호존재하는지 체크
    while (s.find('(') != string::npos)
    {
        // 안쪽 괄호부터 풀어준다 replace : 2(a2(b))
        int left, right;
        left = s.size() - 1;
        right = s.size() - 1;

        while (left > 0 && s[left] != '(')
        {
            left--;
        }
        right = left + 1;
        while (right < s.size() - 1 && s[right] != ')')
        {
            right++;
        }

        // num을 구한다
        int num;
        int num_ix = left - 1;
        while (num_ix > 0 && isdigit(s[num_ix]))
        {
            num_ix--;
        }
        if (!isdigit(s[num_ix]))
            num_ix++;
        num = stoi(s.substr(num_ix, left - num_ix));
        // subStr을 구한다
        string substr = s.substr(left + 1, right - left - 1);

        // s.replace(pos, len, subStr)
        s.replace(num_ix, right - num_ix + 1, func_parenthe(substr, num));

        // debug
        // cout << left << " " << right << num_ix << num << endl;
        // cout << substr << endl;
        // cout << s << endl;
    }

    cout << s << endl;
}

// 3번
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; // 입력 예시 : abc123def45gh6
    cin >> s;
    vector<int> v;
    int sum = 0;

    int left = 0, right = 0;

    while (right < s.size() && left < s.size()) // 숫자가 존재하면
    {
        // 숫자가 나올 때까지 left++
        while (left < s.size() && !isdigit(s[left]))
            left++; // left -> 1

        // 숫자가 끝날 때까지 right++
        right = left;
        while (right < s.size() && isdigit(s[right]))
            right++; // right -> d

        // substr -> 숫자로 변환
        if (left < right)
        {
            string substr = s.substr(left, right - left);
            int num = stoi(substr);
            v.push_back(num);
            sum += num;
        }

        // 변수 초기화
        left = right;
    }

    cout << sum << endl;
}

// 4번
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 회문인지 판단하는 함수
bool ispalindrome(string s)
{
    string rs = s;
    reverse(rs.begin(), rs.end());

    if (rs == s)
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // test();
    string s; // abab
    cin >> s;

    // int left = s.size() - 1;

    // left 를 줄여가면서 팰린드롬인 가장 작은 left 를 찾는다
    int min_ix = s.size() - 1;

    for (int left = s.size() - 1; left >= 0; left--)
    {
        string substr = s.substr(left, s.size() - left);
        if (ispalindrome(substr))
            min_ix = left;
    }

    // 반복해야 하는 부분을 s.append 해 준다.
    string substr2 = s.substr(0, min_ix);
    reverse(substr2.begin(), substr2.end());
    s.append(substr2);

    // cout << min_ix << endl;
    cout << s << endl;
}