#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ifstream file("Day07.txt");
    string s;
    vector<vector<char>> a;
    while (getline(file, s)){
        vector<char> b(s.begin(), s.end());
        a.push_back(b);
    }
    int n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    int pos = 0;
    while(a[0][pos] != 'S'){ 
        pos++;
    }
    dp[0][pos] = 1;
    int count = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < m; j++){
            if (dp[i][j] == 0)     continue;
            if (a[i + 1][j] == '.') {
                dp[i + 1][j] += dp[i][j];
            }
            else {
                int right = j + 1;
                while (right < m && a[i + 1][right] != '.'){
                    right++;
                }
                if (right < m && a[i + 1][right] == '.'){
                    dp[i + 1][right] += dp[i][j];
                }
                int left = j - 1;
                while (left >= 0 && a[i + 1][left] != '.'){
                    left--;
                }
                if (left >= 0 && a[i + 1][left] == '.'){
                    dp[i + 1][left] += dp[i][j];
                }
            }
        }
    }
    for (int i = 0; i < m; i++){
        count += dp[n - 1][i];
    }
    cout << count << "\n";
}
