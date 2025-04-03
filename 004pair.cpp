#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    pair<int, int> t1 = make_pair(10, 13);
    pair<int, int> t2 = {4, 6};
    cout << t2.first << ' ' << t2.second << '\n';
    if (t2 < t1)
        cout << "t2 < t1";

    return 0;
}

void pair_basic()
{
    // 스택에 pair 바로 넣기: {}로 묶어서 넣기
    //  tower.push({height, i});
    // pair 출력하기
    vector<pair<int, int>> tower;
    tower.push_back({1, 2});
    for (auto i : tower)
    {
        cout << i.first << ' ' << i.second << '\n';
    }
}

void pair_sort() // pair 정렬하기, first 기준으로 정렬하고, first가 같으면 second 기준으로 정렬한다.
{
    vector<pair<int, int>> v;
    v.push_back({1, 2});
    v.push_back({2, 3});
    v.push_back({1, 3});
    v.push_back({2, 2});
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i.first << ' ' << i.second << '\n';
    }
}

void 탐색()
{
    // pair를 이용한 탐색
    vector<pair<int, int>> v;
    v.push_back({1, 2});
    v.push_back({2, 3});
    v.push_back({1, 3});
    v.push_back({2, 2});
    pair<int, int> p = {1, 3};
    auto it = find(v.begin(), v.end(), p);
    if (it != v.end())
    {
        cout << "found\n";
    }
    else
    {
        cout << "not found\n";
    }
}