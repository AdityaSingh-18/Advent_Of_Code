#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isSafe(vector<int> &a){
    int n = a.size();
    for (int i = 0; i < a.size() - 1; i++){
        int dif = abs(a[i + 1] - a[i]);
        if((i != 0 && ((a[i - 1] < a[i]) != (a[i] < a[i + 1]))) || (dif < 1 || dif > 3)){
            return false;
        }
    }
    return true;
}

signed main(){
    ifstream file("Day02.txt");
    string s;
    int count = 0;
    while(getline(file, s)){
        stringstream ss(s);
        int x;
        vector<int> a;
        while(ss >> x){
            a.push_back(x);
        }
        if(isSafe(a)){
            count++;
            continue;
        }
        int safe = false;
        for (int i = 0; i < a.size(); i++){
            vector<int> b;
            for (int j = 0; j < a.size(); j++){
                if(i != j)     b.push_back(a[j]);
            }
            if(isSafe(b)){
                safe = true;
                break;
            }
        }
        if(safe)    count++;
    }
    cout << count << "\n";
}