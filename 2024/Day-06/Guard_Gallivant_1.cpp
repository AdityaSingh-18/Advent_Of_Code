#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ifstream file("Day06.txt");
    string s;
    vector<string> grid;
    while(getline(file, s)){
        grid.push_back(s);
    }
    int n = grid.size(), m = grid[0].size();
    int i, j, found = 0;
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if(grid[i][j] != '.' && grid[i][j] != '#'){
                found = 1;
                break;
            }
        }
        if(found)   break;
    }
    vector<vector<int>> visited(n, vector<int> (m, 0));
    visited[i][j] = 1;
    int count = 1;
    while(i > 0 && j > 0 && i < (n - 1) && j < (m - 1)){
        if(grid[i][j] == '^'){
            while(i > 0 && grid[i - 1][j] != '#'){
                if(visited[i - 1][j] == 0){
                    visited[i - 1][j] = 1;
                    count++;
                }
                i--;
            }
            if(i == 0)   break;
            else    grid[i][j] = '>';
        }
        if(grid[i][j] == '>'){
            while(j < (m - 1) && grid[i][j + 1] != '#'){
                if(visited[i][j + 1] == 0){
                    visited[i][j + 1] = 1;
                    count++;
                }
                j++;
            }
            if(j == (m - 1))   break;
            else    grid[i][j] = 'v';
        }
        if(grid[i][j] == 'v'){
            while(i < (n - 1) && grid[i + 1][j] != '#'){
                if(visited[i + 1][j] == 0){
                    visited[i + 1][j] = 1;
                    count++;
                }
                i++;
            }
            if(i == (n - 1))   break;
            else    grid[i][j] = '<';
        }
        if(grid[i][j] == '<'){
            while(j > 0 && grid[i][j - 1] != '#'){
                if(visited[i][j - 1] == 0){
                    visited[i][j - 1] = 1;
                    count++;
                }
                j--;
            }
            if(j == 0)   break;
            else    grid[i][j] = '^';
        }
    }
    cout << count << "\n";
}