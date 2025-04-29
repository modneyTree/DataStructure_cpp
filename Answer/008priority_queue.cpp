#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <cmath>


#define endl '\n' // 코테용 추천

using namespace std;

void S1();
void S2();
void S3();

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // S1();
    // S2();
    S3();

}

// 
void S1() {
    int n;
    cin >> n;

    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    while(n--) {
        int temp;
        cin >> temp;
        // 0 이면 출력 아니면 push
        if (temp == 0) {
            if (!pq.empty()) {
                cout << pq.top().second << endl;
                pq.pop();
            } else {
                cout << 0 << endl;
            }
        } else {
            pq.push({abs(temp),temp});
        }
    }

}

// S2 람다 버젼도 작성해보자
void S2() {
    int n;
    cin >> n;

    auto f = [](pair<int,int> a, pair<int,int> b)  {
        return a > b;
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(f)> pq(f);
    
    while(n--) {
        int temp;
        cin >> temp;

        if (temp == 0 ) {
            if (!pq.empty()) {
                cout << pq.top().second << endl;
                pq.pop();
            } else {
                cout << 0 << endl;
            }
        } else {
            pq.push({abs(temp), temp});
        }
        
    }
}

struct Compare {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a > b;
    }
};

// Struct 방식도 작성해보자
void S3() {
    int n;
    cin >> n;


    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
    
    while(n--) {
        int temp;
        cin >> temp;

        if (temp == 0 ) {
            if (!pq.empty()) {
                cout << pq.top().second << endl;
                pq.pop();
            } else {
                cout << 0 << endl;
            }
        } else {
            pq.push({abs(temp), temp});
        }
        
    }
}