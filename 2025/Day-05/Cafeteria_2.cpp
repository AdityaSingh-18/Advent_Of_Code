#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ifstream file("Day05.txt");
    string s;
    vector<pair<int, int>> a, b;
    while(getline(file, s)){
        if (s.empty())     break;
        int start = stoll(s.substr(0, s.find('-')));
        int end = stoll(s.substr(s.find('-') + 1));
        a.push_back({start, end});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++){
        if(b.empty() || b.back().second < a[i].first){
            b.push_back({a[i].first, a[i].second});
        }
        else    b.back().second = max(b.back().second, a[i].second);
    }
    int totalCount = 0;
    for (int i = 0; i < b.size(); i++){
        totalCount += b[i].second - b[i].first + 1;
    }
    cout << totalCount << "\n";
}