#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

/*
목차
1. 스택 기본 사용법
  1) push, pop, top, size, empty
주의사항 : s.pop() 전에 s.empty() 꼭 확인!
2. 예제
  1) 문자열 뒤집기
  2) 괄호 유효성 검사
  3) 후위 표기식 계산
*/

// 1) 문자열 뒤집기
void reverseString()
{
  string str = "abcde";
  stack<char> s;
  for (char c : str)
    s.push(c);

  cout << "[문자열 뒤집기] ";
  while (!s.empty())
  {
    cout << s.top();
    s.pop();
  }
  cout << endl;
}

// 2) 괄호 유효성 검사
void checkParentheses()
{
  string str = "(()())";
  stack<char> s;
  bool isValid = true;

  for (char c : str)
  {
    if (c == '(')
      s.push(c);
    else
    {
      if (s.empty())
      {
        isValid = false;
        break;
      }
      s.pop();
    }
  }
  if (!s.empty())
    isValid = false;

  cout << "[괄호 검사] " << (isValid ? "YES" : "NO") << endl;
}

// 3) 후위 표기식 계산
void postfixEval()
{
  string expr = "23+5*"; // (2 + 3) * 5 = 25
  stack<int> s;

  for (char c : expr)
  {
    if (isdigit(c))
      s.push(c - '0');
    else
    {
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      if (c == '+')
        s.push(a + b);
      else if (c == '-')
        s.push(a - b);
      else if (c == '*')
        s.push(a * b);
      else if (c == '/')
        s.push(a / b);
    }
  }

  cout << "[후위 계산] " << s.top() << endl;
}

// 기본 사용법 시연
void basicStackUsage()
{
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);

  cout << "[기본 사용법]" << endl;
  cout << "Size: " << s.size() << endl;
  cout << "Top: " << s.top() << endl;

  s.pop();
  cout << "Top after pop: " << s.top() << endl;

  s.pop();
  s.pop();
  cout << "Empty? " << (s.empty() ? "Yes" : "No") << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  basicStackUsage();
  cout << "-------------------" << endl;

  reverseString();
  cout << "-------------------" << endl;

  checkParentheses();
  cout << "-------------------" << endl;

  postfixEval();
  cout << "-------------------" << endl;

  return 0;
}
