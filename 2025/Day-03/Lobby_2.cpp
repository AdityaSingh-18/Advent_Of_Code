#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ifstream file("Day03.txt");
    ll totalSum = 0;
    string s;
    while (file >> s) {
        string maxJolt;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            while (!maxJolt.empty() && maxJolt.back() < s[i] && (maxJolt.size() + (n - i)) > 12) {
                maxJolt.pop_back();
            }
            if (maxJolt.size() < 12)    maxJolt.push_back(s[i]);
        }
        totalSum += stoll(maxJolt); 
    }
    cout << totalSum << "\n";
}
