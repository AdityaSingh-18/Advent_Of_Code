#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ifstream file("Day05.txt");
    string s;
    vector<pair<int, int>> a;
    vector<int> b;
    while(getline(file, s)){
        if (s.empty())     continue;
        if(s.find('-') != string::npos){
            int start = stoll(s.substr(0, s.find('-')));
            int end = stoll(s.substr(s.find('-') + 1));
            a.push_back({start, end});
        }
        else    b.push_back(stoll(s));
    }
    int count = 0;
    for (int i = 0; i < b.size(); i++){
        bool fresh = false;
        for (int j = 0; j < a.size(); j++){
            if(b[i] >= a[j].first && b[i] <= a[j].second){
                fresh = true;
                break;
            }
        }
        if(fresh)   count++;
    }
    cout << count << "\n";
}