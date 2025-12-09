#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ifstream file("Day04.txt");
    vector<string> grid;
    string s;
    while(getline(file, s)){
        grid.push_back(s);
    }
    int count = 0;
    int n = grid.size(), m = grid[0].size();
    for (int i = 1; i < n - 1; i++){
        for (int j = 1; j < m - 1; j++){
            bool diag1 = false, diag2 = false;
            if(grid[i][j] == 'A'){
                int x1 = grid[i - 1][j - 1], x2 = grid[i + 1][j + 1];
                int y1 = grid[i - 1][j + 1], y2 = grid[i + 1][j - 1];
                if((x1 == 'M' && x2 == 'S') || (x1 == 'S' && x2 == 'M'))    diag1 = true;
                if((y1 == 'M' && y2 == 'S') || (y1 == 'S' && y2 == 'M'))    diag2 = true;
                if(diag1 && diag2)    count++;
            }
        }
    }
    cout << count << "\n";
}

/*
if(grid[i - 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'S' && grid[i - 1][j + 1] == 'M' && grid[i + 1][j - 1] == 'S') count++; 
if(grid[i - 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'S' && grid[i - 1][j + 1] == 'S' && grid[i + 1][j - 1] == 'M') count++; 
if(grid[i - 1][j - 1] == 'S' && grid[i + 1][j + 1] == 'M' && grid[i - 1][j + 1] == 'M' && grid[i + 1][j - 1] == 'S') count++; 
if(grid[i - 1][j - 1] == 'S' && grid[i + 1][j + 1] == 'M' && grid[i - 1][j + 1] == 'S' && grid[i + 1][j - 1] == 'M') count++;
*/