#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ifstream file("Day01.txt");
    string s;
    unordered_map<int, int> a, b;
    while(getline(file, s)){
        stringstream ss(s);
        int x, y;
        while(ss >> x >> y){
            a[x]++;
            b[y]++;
        }
    }
    int ans = 0;
    for (auto &i : a){
        ans += (i.first * i.second * b[i.first]);
    }
    cout << ans << "\n";
}