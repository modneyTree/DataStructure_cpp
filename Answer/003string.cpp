#include <iostream>
#include <algorithm> // remove 포함
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    reverse(s.begin(), s.end());

    cout << s << endl;
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

    string s;
    getline(cin, s);
    string target;
    cin >> target;

    auto f = s.find(target);
    if (f == string::npos)
        cout << -1 << endl;
    else
        cout << f << endl;
}

// 3번
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

    string s;
    cin >> s;

    int pos, len;
    cin >> pos >> len;

    s.erase(pos, len);

    cout << s << endl;
}

// 4번
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

    string s;
    getline(cin, s);

    int pos, len;
    string replace_str;
    cin >> pos >> len >> replace_str;

    s.replace(pos, len, replace_str);
    cout << s << endl;
}

// 5번
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

    string s;
    cin >> s;

    int pos, len;
    cin >> pos >> len;

    string s2 = s.substr(pos, len);
    cout << s2 << endl;
}

// 6번
#include <iostream>
#include <string>

#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int result = s1.compare(s2);

    if (result > 0)
        cout << 1 << endl;
    else if (result < 0)
        cout << -1 << endl;
    else
        cout << 0 << endl;
}
