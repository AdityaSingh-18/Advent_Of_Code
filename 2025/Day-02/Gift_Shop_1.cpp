#include <bits/stdc++.h>
using namespace std;
#define int long long

int pow10(int d) {
    int next = 1;
    while (d--){
        next *= 10;
    }
    return next;
}

int checkRange(int start, int end){
    int sum = 0;
    while (start <= end) {
        int dStart = to_string(start).size();
        if (dStart % 2 == 1) {
            int nextStart = pow10(dStart);
            if (nextStart > end)    break;
            start = nextStart;
            continue;
        }
        int blockEnd = pow10(dStart) - 1;
        if (blockEnd > end)     blockEnd = end;
        int half = dStart / 2;
        int L = pow10(half - 1);
        int R = pow10(half) - 1;
        for (int i = L; i <= R; i++) {
            int val = i * pow10(half) + i;
            if (val < start)    continue;
            if (val > blockEnd)     break;
            sum +=val;
        }
        start = blockEnd + 1;
    }
    return sum;
}

signed main() {
    ifstream file("Day02.txt");
    int totalSum = 0;
    string s;
    while (getline(file, s, ',')) {
        int start = stoll(s.substr(0, s.find('-')));
        int end = stoll(s.substr(s.find('-') + 1));
        totalSum += checkRange(start, end);
    }
    cout << totalSum << "\n";
}