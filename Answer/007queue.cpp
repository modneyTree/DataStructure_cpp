// 1번 문제
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <cmath>

#define endl '\n' // 코테용 추천

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while(q.size() != 1) {
        q.pop();
        int k = q.front();
        q.pop();
        q.push(k);
    }

    if(!q.empty())
        cout << q.front() << endl;

}

// 2번 문제
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <cmath>

#define endl '\n' // 코테용 추천

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<string> q;

    while(n--) {
        string cmd;
        cin >> cmd;

        if (cmd == "arrive") {
            string s;
            cin >> s;
            q.push(s);
        } else if (cmd == "process") {
            if (!q.empty()) {
                cout << q.front() << endl;
                q.pop();
            } else {
                cout << "process fail: empty " << endl;
            }
            
        } else if (cmd == "size") {
            cout << q.size() << endl;
        } else if (cmd == "empty") {
            if (q.empty()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            cout << "error" << endl;
        }
    }
}

// 3번 문제
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <cmath>


#define endl '\n' // 코테용 추천

using namespace std;

void S1();  // vector, find 를 활용한
void S2();  // unordered_set를 활용한 (가장 추천)
void S3();  // queue 사용

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // S1();
    S2();
    // S3();

}

void S1() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n+1);

    for (int i = 1; i <= n; i++) {
        v[i] = i;
    }

    while(m--) {
        int in;
        cin >> in;

        auto iter = find(v.begin(), v.end(), in);
        if (iter != v.end()) {
            v[distance(v.begin(), iter)] = -1;
        }
        
    }

    // print
    for (int i = 1; i <= n; i++) {
        if (v[i] != -1)
            cout << v[i] <<  " ";
    }
    cout << endl;
}

void S2() {
    int n, m;
    cin >> n >> m;

    unordered_set<int> removed;

    while(m--) {
        int temp;
        cin >> temp;
        removed.insert(temp);
    }

    for (int i = 1; i <= n; i++) {
        if (!removed.count(i))
            cout << i << " ";
    }
    cout << endl;
    
}

void S3() {
    int n, m;
    cin >> n >> m;

    // 제거할 번호 저장
    unordered_set<int> removed;
    while (m--) {
        int x;
        cin >> x;
        removed.insert(x);
    }

    // 큐에 1~n 넣기
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    // 남은 사람 출력
    while (!q.empty()) {
        int front = q.front(); q.pop();
        if (!removed.count(front)) {
            cout << front << " ";
        }
    }

    cout << '\n';
}

// 4번
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <cmath>


#define endl '\n' // 코테용 추천

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    queue<pair<string,int>> q;  // <명칭,남은시간>

    // 처음 큐에 삽입
    while(n--) {
        pair<string,int> pr;
        cin >> pr.first >> pr.second;
        q.push(pr);
    }

    // 라운드 로빈 로직
    while(!q.empty()) {
        // 매 번 top의 남은 시간을 k 마큼 둘이고 push 한다
        // if 남은 시간이 0 이하가 되면 push 하지 않는다.
        pair<string,int> pr = q.front();
        q.pop();
        pr.second -= k;

        if (pr.second > 0) {
            q.push(pr);
        } else {
            cout << pr.first << " ";
        }
    }
    cout << endl;
    //
    
}
