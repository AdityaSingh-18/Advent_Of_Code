#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ifstream file("Day09.txt");
    string s;
    vector<pair<int, int>> a;
    while(getline(file, s)){
        stringstream ss(s);
        int x, y;
        char c;
        while(ss >> x >> c >> y){
            a.push_back({x, y});
        }
    }
    int maxArea = 0;
    for(int i = 0; i < a.size() - 1; i++){
        for (int j = i + 1; j < a.size(); j++){
            maxArea = max (maxArea, (abs(a[i].first - a[j].first) + 1) * (abs(a[i].second - a[j].second) + 1));
        }
    }
    cout << maxArea << "\n";
}