#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isRepeated(int i) {
    string s = to_string(i);
    int n = s.size();
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            bool possible = true;
            int len = n / i;
            string first = s.substr(0, len);
            for (int j = 1; j < i; j++) {
                if (s.substr(len * j, len) != first) {
                    possible = false;
                    break;
                }
            }
            if (possible)   return true;
        }
    }
    return false;
}

signed main() {
    ifstream file("Day02.txt");
    int totalSum = 0;
    string s;
    while (getline(file, s, ',')) {
        int start = stoll(s.substr(0, s.find('-')));
        int end = stoll(s.substr(s.find('-') + 1));
        for (int i = start; i <= end; i++) {
            if (isRepeated(i)) {
                totalSum += i;
            }
        }
    }
    cout << totalSum << "\n";
}
