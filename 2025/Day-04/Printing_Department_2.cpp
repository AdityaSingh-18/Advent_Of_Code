#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ifstream file("Day04.txt");
    string s;
    vector<vector<char>> a;
    while(getline(file, s)){
        a.push_back(vector<char> (s.begin(), s.end()));
    }
    int n = a.size(), m = a[0].size();
    int totalCount = 0;
    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
    while (true) {
        int totalRemoved = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != '@')    continue;
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (a[ni][nj] == '@')    count++;
                    }
                }
                if (count < 4){
                    a[i][j] = '.';
                    totalRemoved++;
                }
            }
        }
        if(totalRemoved == 0)    break;
        totalCount += totalRemoved;
    }
    cout << totalCount << "\n";
}