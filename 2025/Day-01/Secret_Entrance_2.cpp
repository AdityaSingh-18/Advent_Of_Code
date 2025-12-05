#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ifstream file("Day01.txt");
    string s;
    int current = 50, count = 0;
    while (getline(file, s)) {
        char sign = s[0];
        int angle = stoi(s.substr(1));
        if (sign == 'R') {
            int gap = (100 - current) % 100;
            if (gap == 0)   gap = 100;  
            if (angle >= gap)    count += 1 + (angle - gap) / 100;
            current = (current + angle) % 100;
        }
        else {
            int gap = current % 100;    
            if (gap == 0)    gap = 100;
            if (angle >= gap)    count += 1 + (angle - gap) / 100;          
            current = (current - angle % 100 + 100) % 100;
        }
    }
    cout << count << "\n";
}
