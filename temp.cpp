#include <iostream>
#include <vector>
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

    vector<string> vs;
    while(ss >> s)
        vs.push_back(s);

    for (string k : vs)
        cout << k << " ";
    
}
// 변경