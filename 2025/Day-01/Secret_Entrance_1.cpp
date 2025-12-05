#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ifstream file("Day01.txt");
    string s;
    int current = 50, count = 0;
    while (getline(file, s)) {
        char sign = s[0];
        int angle = stoi(s.substr(1));
        angle %= 100;
        if(sign == 'R')    current = (current + angle) % 100;
        else    current = (current - angle + 100) % 100;
        if(current == 0)    count++;
    }
    cout << count << "\n";
}