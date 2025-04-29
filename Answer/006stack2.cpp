// 1번 내 풀이(구조적 빈약약) : 백준 10799 테스트는 통과
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <cctype>

#define endl '\n'

using namespace std;

// 함수 선언

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int cnt = 0;
    int bar; // 총 가로 막대기 수
    stack<int> st;

    for (int i = 0; i < s.size() - 1; i++)
    {
        // ch가  (  -> 레이저 or 막대기
        if (s[i] == '(')
        {
            if (s[i + 1] == ')')
            {                     // 레이저
                cnt += st.size(); // 레이저가 나올 때마다 스택의 크기만큼 더해준다
            }
            else
            {
                bar++;
                st.push('(');
            }
        }
        else
        {
            if (s[i - 1] != '(') // 레이저가 아니라 막대기일 때
                st.pop();
        }
    }

    // print
    cout << cnt + bar << endl;
}

// raser가 나오면 st.size()를 더한다
// 레이저 or 막대기 판단

// 1번 정답(깔끔)
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<char> st;
    int result = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            st.push('(');
        }
        else
        {             // s[i] == ')'
            st.pop(); // 무조건 pop

            if (s[i - 1] == '(')
            {
                // 레이저
                result += st.size();
            }
            else
            {
                // 막대기 끝
                result += 1;
            }
        }
    }

    cout << result << '\n';
}

// 2번 문제
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    stringstream ss(s);

    stack<int> st;
    char ch;

    while (ss >> ch)
    {
        if (isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            if (st.size() < 2)
            {
                cout << "error: not enough operands" << endl;
                return 0;
            }

            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if (ch == '+')
                st.push(a + b);
            else if (ch == '-')
                st.push(a - b);
            else if (ch == '*')
                st.push(a * b);
            else if (ch == '/')
            {
                if (b == 0)
                {
                    cout << "error: division by zero" << endl;
                    return 0;
                }
                st.push(a / b);
            }
            else
            {
                cout << "error: unknown operator" << endl;
                return 0;
            }
        }
    }

    if (st.size() == 1)
        cout << st.top() << '\n';
    else
        cout << "error: leftover operands" << endl;

    return 0;
}

// 3번 문제
// 2번 문제
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> st;
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;

        // stack logic : push, pop()

        // 큰게 나오거나 빌 때까지
        while (!st.empty() && st.top() <= in)
        {
            st.pop();
        }
        if (st.empty())
            result.push_back(-1);
        else
            result.push_back(st.top());

        st.push(in);
    }

    // print
    for (int k : result)
        cout << k << " ";
    cout << endl;
}

// 4번 문제
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<string> st;
    string word;
    bool isvalid = true;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '<')
        {
            word = "";
        }
        else if (s[i] == '>')
        {
            if (word[0] != '/')
            {
                st.push(word);
            }
            else
            {
                if (st.empty() || st.top() != word.substr(1))
                {
                    isvalid = false;
                    break;
                }
                st.pop();
            }
        }
        else
        {
            word.push_back(s[i]); // 👍 더 직관적인 방식
        }
    }

    if (!st.empty())
        isvalid = false;

    cout << (isvalid ? "YES\n" : "NO\n");
    return 0;
}

// 5번 문제
// 2번 문제
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

#define endl "\n"

using namespace std;

void temp()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> v;

    while (n--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "type")
        {
            string temp;
            cin >> temp;
            v.push_back(temp);
        }
        else if (cmd == "undo")
        {
            if (!v.empty())
                v.pop_back();
        }
        else
        {
            cout << "error" << endl;
        }
    }

    // print
    for (string k : v)
        cout << k;
    cout << endl;
}
