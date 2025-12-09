#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ifstream file("Day04.txt");
    vector<string> grid;
    string s;
    string target = "XMAS";
    while(getline(file, s)){
        grid.push_back(s);
    }
    int count = 0;
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(grid[i][j] == 'X'){
                for (auto dir : directions)
                {
                    int x = i, y = j;
                    for (int k = 1; k <= 3; k++)
                    {
                        x += dir.first;
                        y += dir.second;
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == target[k]){
                            if (k == 3)    count++;
                        }
                        else    break;
                    }
                }
            }
        }
    }
    cout << count << "\n";
}

/* 
Noob
if((i - 3) >= 0 && a[i - 1][j] == 'M' && a[i - 2][j] == 'A' && a[i - 3][j] == 'S')   count++;
if((i + 3) < n && a[i + 1][j] == 'M' && a[i + 2][j] == 'A' && a[i + 3][j] == 'S')   count++;
if((j - 3) >= 0 && a[i][j - 1] == 'M' && a[i][j - 2] == 'A' && a[i][j - 3] == 'S')   count++;
if((j + 3) < m && a[i][j + 1] == 'M' && a[i][j + 2] == 'A' && a[i][j + 3] == 'S')   count++;
if((i - 3) >= 0 && (j - 3) >= 0 && a[i - 1][j - 1] == 'M' && a[i - 2][j - 2] == 'A' && a[i - 3][j - 3] == 'S')   count++; 
if((i + 3) < n && (j + 3) < m && a[i + 1][j + 1] == 'M' && a[i + 2][j + 2] == 'A' && a[i + 3][j + 3] == 'S')   count++; 
if((i - 3) >= 0 && (j + 3) < m && a[i - 1][j + 1] == 'M' && a[i - 2][j + 2] == 'A' && a[i - 3][j + 3] == 'S')   count++; 
if((i + 3) < n && (j - 3) >= 0 && a[i + 1][j - 1] == 'M' && a[i + 2][j - 2] == 'A' && a[i + 3][j - 3] == 'S')   count++;  
*/