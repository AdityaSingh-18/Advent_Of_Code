#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ifstream file("Day01.txt");
    string s;
    vector<int> a, b;
    while(getline(file, s)){
        stringstream ss(s);
        int x, y;
        while(ss >> x >> y){
            a.push_back(x);
            b.push_back(y);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < a.size(); i++){
        ans += abs(a[i] - b[i]);
    }
    cout << ans << "\n";
}