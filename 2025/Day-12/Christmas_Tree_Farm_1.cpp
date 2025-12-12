#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ifstream file("Day12.txt");
    string s;
    vector<string> lines;
    while (getline(file, s)){
        lines.push_back(s);
    }
    vector<int> shapeCount;
    int n = lines.size(), i = 0;
    while (i < n) {
        if (lines[i].find('x') != string::npos)     break;
        if (lines[i].find(':') == string::npos){ 
            i++;
            continue; 
        }
        int count = 0;
        for (int j = 0; j < 3 && (i + j + 1) < n; j++) {
            string &row = lines[i + j + 1];
            for (int k = 0; k < 3 && k < row.size(); k++) {
                if (row[k] == '#')    count++;
            }
        }
        shapeCount.push_back(count);
        i += 4;
    }
    int fit = 0;
    for (; i < n; i++) {
        string &region = lines[i];
        if (region.empty())     continue;
        int x = region.find('x');
        int colon = region.find(':');
        if (x == string::npos || colon == string::npos)     continue;
        int width = stoi(region.substr(0, x));
        int height = stoi(region.substr(x + 1, colon - x - 1));
        string giftCount = region.substr(colon + 1);
        stringstream ss(giftCount);
        vector<int> gift;
        int val;
        while (ss >> val){
            gift.push_back(val);
        }
        int totalGift = accumulate(gift.begin(), gift.end(), 0LL);
        if ((width / 3) * (height / 3) >= totalGift)    fit++;
    }
    cout << fit << "\n";
}