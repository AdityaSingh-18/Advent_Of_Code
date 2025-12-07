#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ifstream file("Day07.txt");
    string s;
    vector<vector<char>> a;
    while(getline(file, s)){
        vector<char> b(s.begin(), s.end());
        a.push_back(b);
    }
    int n = a.size(), m = a[0].size();
    int count = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < m; j++){
            if((a[i][j] == 'S') || a[i][j] == '|'){
                if(a[i + 1][j] == '.' || a[i + 1][j] == '|'){
                    a[i + 1][j] = '|';
                }
                else{
                    count++;
                    int right = j + 1;
                    while(right < m && a[i + 1][right] != '.' && a[i + 1][right] != '|'){
                        right++;
                    }
                    if(right < m && a[i + 1][right] == '.'){
                        a[i + 1][right] = '|';
                    }
                    int left = j - 1;
                    while(left >= 0 && a[i + 1][left] != '.' && a[i + 1][left] != '|'){
                        left--;
                    }
                    if(left >= 0 && a[i + 1][left] == '.'){
                        a[i + 1][left] = '|';
                    }
                }
            }
        }
    }
    cout << count << "\n";
}