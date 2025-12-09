#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ifstream file("Day03.txt");
    string s;
    regex pattern(R"(mul\(([0-9]{1,3}),([0-9]{1,3})\))");
    int productSum = 0;
    while (getline(file, s)) {
        for (sregex_iterator it(s.begin(), s.end(), pattern), end; it != end; it++) {
            int x = stoi((*it)[1].str());
            int y = stoi((*it)[2].str());
            productSum += x * y;
        }
    }
    cout << productSum << "\n";
}
