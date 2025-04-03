
// 1번번
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

#define endl "\n"

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v;
    v.resize(n);

    // input
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // 3을 삭제
    vector<int> v2;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 3)
        {
            cnt++;
        }
        else
            v2.push_back(v[i]);
    }

    sort(v2.begin(), v2.end());

    cout << "3의 개수 : " << cnt << endl;
    for (int k : v2)
        cout << k << " ";
}

// 다른 버전
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    int cnt = count(v.begin(), v.end(), 3);
    v.erase(remove(v.begin(), v.end(), 3), v.end());
    sort(v.begin(), v.end());

    cout << "3의 개수 : " << cnt << "\n";
    for (int x : v)
        cout << x << " ";
}

// 2번
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

#define endl "\n" // endl → "\n" 성능 향상용 매크로

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
            rowSum += v[i][j];
        }
        cout << "Row " << i << " sum: " << rowSum << "\n";
    }
}

// 3번
#include <iostream>
#include <algorithm>
#include <vector>

#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int k = 0;
    cout << "찾을 숫자 입력: ";
    cin >> k;

    auto f = find(v.begin(), v.end(), k);

    if (f != v.end())
    {
        cout << k << "은 인덱스 " << distance(v.begin(), f) << "에 있습니다." << endl;
    }
    else
    {
        cout << k << "은 벡터에 없습니다." << endl;
    }
}
