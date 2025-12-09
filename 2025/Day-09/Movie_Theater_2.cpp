#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ifstream file("Day09.txt");
    string s;
    vector<pair<int, int>> a;
    while (getline(file, s)) { 
        stringstream ss(s);
        int x, y;
        char c;
        while (ss >> x >> c >> y) {
            a.push_back({x, y});
        }
    }
    int n = a.size();
    int maxArea = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = a[i].first, y1 = a[i].second;
            int x2 = a[j].first, y2 = a[j].second;
            int minX = min(x1, x2), minY = min(y1, y2);
            int maxX = max(x1, x2), maxY = max(y1, y2);
            bool valid = true;
            for (int k = 0; k < n; k++) {
                int curX = a[k].first, curY = a[k].second;
                int nextX = a[(k + 1) % n].first, nextY = a[(k + 1) % n].second;
                if (minX < max(curX, nextX) && maxX > min(curX, nextX) && 
                    minY < max(curY, nextY) && maxY > min(curY, nextY)) {
                    valid = false;
                    break;
                }
            }
            if (valid){
                maxArea = max(maxArea, (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1));
            }
        }
    }
    cout << maxArea << endl;
}