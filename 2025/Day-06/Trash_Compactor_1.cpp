#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ifstream file("Day06.txt");
    vector<vector<string>> a;
    string line, s;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        while (ss >> s) { 
            row.push_back(s);
        }
        a.push_back(row);
    }
    int total = 0;
    int n = a.size(), m = a[0].size();
    for (int col = 0; col < m; col++) {
        int prod = 1, sum = 0;
        for (int row = 0; row < n - 1; row++) {
            if (a[n - 1][col] == "*")
                prod *= stoi(a[row][col]);
            else
                sum += stoi(a[row][col]);
        }
        if (a[n - 1][col] == "*") total += prod;
        else total += sum;
    }
    cout << total << "\n";
}
