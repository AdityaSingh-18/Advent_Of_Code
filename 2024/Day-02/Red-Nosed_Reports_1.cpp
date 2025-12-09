#include <bits/stdc++.h>
using namespace std;
#define int long long

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
        bool safe = true;
        for (int i = 0; i < a.size() - 1; i++){
            int dif = abs(a[i + 1] - a[i]);
            if((i != 0 && ((a[i - 1] < a[i]) != (a[i] < a[i + 1]))) || (dif < 1 || dif > 3)){
                safe = false;
                break;
            }
        }
        if(safe)    count++;
    }
    cout << count << "\n";
}