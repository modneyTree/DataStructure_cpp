// 1번
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

#define endl '\n'

using namespace std;

// 함수 선언

// 전역 변수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 변수 선언, 초기화
    vector<pair<int, int>> v;

    int n;
    cin >> n;

    while (n--)
    {
        pair<int, int> pr;
        cin >> pr.first >> pr.second;
        v.push_back(pr);
    }

    sort(v.begin(), v.end());

    for (auto pr : v)
        cout << pr.first << " " << pr.second << endl;

    // 로직
}

// 2번
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // vector를 stack 처럼 사용하겠다.
    vector<pair<int, int>> s;

    int n;
    cin >> n;

    while (n--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push")
        {
            int a, b;
            cin >> a >> b;
            s.push_back({a, b});
        }
        else if (cmd == "pop")
        {
            if (!s.empty())
                s.pop_back();
        }
        else if (cmd == "find")
        {
            pair<int, int> pr;
            cin >> pr.first >> pr.second;
            if (find(s.begin(), s.end(), pr) != s.end())
            {
                cout << "Found" << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }
        }
        else if (cmd == "print")
        {
            for (auto k : s)
                cout << k.first << " " << k.second << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }
}

// 3번
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>

#define endl "\n"

using namespace std;

double distance(pair<int, int> A, pair<int, int> B)
{
    double res;
    res = (B.first - A.first) * (B.first - A.first) + (B.second - A.second) * (B.second - A.second);

    return sqrt(res);
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int, int> A;
    pair<int, int> B;

    vector<pair<int, int>> v; // 좌표를 저장한다

    int n;
    cin >> n;

    while (n--)
    {
        pair<int, int> pr;
        cin >> pr.first >> pr.second;
        v.push_back(pr);
    }

    double min_distance = INT_MAX;

    // 모든 길이 비교(탐색) v[i] : pair<int,int>
    for (int i = 0; i < v.size(); i++)
        for (int j = i + 1; j < v.size(); j++)
        {
            double d = distance(v[i], v[j]);
            if (d < min_distance)
            {
                min_distance = d;
                A = v[i];
                B = v[j];
            }
        }

    cout << fixed << setprecision(2);
    cout << "(" << A.first << ", " << A.second << ") ";
    cout << "(" << B.first << ", " << B.second << ") ";
    cout << min_distance << "\n";
}

// 문제4 풀이1
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    map<int, int> freq;

    while (n--)
    {
        cin >> x;
        freq[x]++;
    }

    for (auto &p : freq)
    {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}

// 문제4 풀이2
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    unordered_map<int, int> freq;
    vector<int> nums;

    while (n--)
    {
        cin >> x;
        if (freq[x] == 0)
            nums.push_back(x); // 처음 본 숫자만 저장
        freq[x]++;
    }

    sort(nums.begin(), nums.end()); // 수를 직접 정렬

    for (int num : nums)
    {
        cout << num << " " << freq[num] << "\n";
    }

    return 0;
}

// 문제4 풀이3 : 명세에 가장 정확
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<pair<int, int>> result;

    int count = 1;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] == arr[i - 1])
        {
            count++;
        }
        else
        {
            result.push_back({arr[i - 1], count});
            count = 1;
        }
    }
    result.push_back({arr[n - 1], count}); // 마지막 값 추가

    for (auto &p : result)
    {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
