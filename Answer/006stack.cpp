// 1 번문제제
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

    stack<int> st;
    bool isvalid = true;

    string s;
    cin >> s;

    for (char ch : s)
    {
        if (ch == '(')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                isvalid = false;
                break;
            }
            st.pop();
        }
    }

    if (isvalid && st.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

// 2번 문제 : 오답(내 풀이)
// 아래 코드가 잘못된 이유를 함께 찾아보자
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

    int n;
    cin >> n;
    stack<int> st;
    st.push(1);
    cout << "+" << endl;
    int num = 2; // 스택에 삽입할 숫자
    bool isvalid = true;

    // n 번 입력받는다
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;

        // in이 나올 때까지 push
        while (in != st.top())
        { // 스택의 top과 in이 같지 않으면 push
            // 예외처리 : in < num 이면 에러
            st.push(num);
            cout << "+" << endl;
            num++;
        }

        st.pop(); // in에 해당하는 값 pop()
        cout << "-" << endl;
        // 예외처리
    }
}

// 2번 문제 : 정답
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

    int n;
    cin >> n;

    stack<int> st;
    string result;
    bool isvalid = true;

    int num = 1; // push 할 숫자

    for (int i = 0; i < n; i++)
    {
        int in; // 4
        cin >> in;

        // num 이 in 보다 작을 때(같아질 쌔?) 까지 push
        while (in >= num)
        { // 4 >= 1
            st.push(num++);
            result.append("+\n");
        }

        // in == num 이면 pop() : 아니면 error
        if (in == st.top())
        {
            st.pop();
            result.append("-\n");
        }
        else
        {
            isvalid = false;
            break;
        }
    }

    if (isvalid)
    {
        cout << result;
    }
    else
        cout << "No" << endl;
}

// 3번 문제
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

    stack<char> st;

    for (char ch : s)
    {
        st.push(ch);
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

// 4번 문제
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

    int arr[10000] = {
        0,
    };
    int top = 0;

    int n;
    cin >> n;

    string cmd;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            int a;
            cin >> a;

            arr[top++] = a;
        }
        else if (cmd == "pop")
        {
            cout << arr[top - 1] << endl;
            top--;
        }
        else if (cmd == "top")
        {
            cout << arr[top - 1] << endl;
        }
        else if (cmd == "size")
        {
            cout << top << endl;
        }
        else if (cmd == "empty")
        {
            if (top < 0)
            {
                cout << "empty" << endl;
            }
            else
            {
                cout << "not empty" << endl;
            }
        }
        else
        {
            cout << "cmd error" << endl;
        }
    }
}

// 5번 문제
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

    int n;
    cin >> n;

    stack<pair<int, int>> st;
    vector<int> result;
    pair<int, int> in;

    for (int i = 1; i <= n; i++)
    {
        cin >> in.first;
        in.second = i;

        while (!st.empty() && in.first > st.top().first) // 예외처리 필요
        {
            st.pop();
        }

        // top() 이 더 큰 상황 or empty
        if (st.empty())
            result.push_back(0);
        else
        {
            result.push_back(st.top().second);
        }
        st.push(in);
    }

    for (int k : result)
        cout << k << " ";
    cout << endl;
}
