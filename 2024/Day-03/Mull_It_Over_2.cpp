#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ifstream file("Day03.txt");
    string s;
    regex pattern(R"(mul\(([0-9]{1,3}),([0-9]{1,3})\)|do\(\)|don't\(\))");
    int productSum = 0;
    bool enabled = true;
    while (getline(file, s)) {
        for (sregex_iterator it(s.begin(), s.end(), pattern), end; it != end; it++) {
            if(it->str() == "do()")    enabled = true;
            else if(it->str() == "don't()")   enabled = false;
            else if (enabled && (*it)[1].matched && (*it)[2].matched) {
                int x = stoi((*it)[1].str());
                int y = stoi((*it)[2].str());
                productSum += x * y;
            }
        }
    }
    cout << productSum << "\n";
}
