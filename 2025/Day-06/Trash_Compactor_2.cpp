#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ifstream file("Day06.txt");
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    string symRow = lines.back();
    vector<int> len;
    int i = 1;
    while (i < symRow.size()) {
        int lastSpace = i - 1;
        while (i < symRow.size() && symRow[i] == ' '){
            i++;
        }
        int width = i - lastSpace;
        if(i < symRow.size())    len.push_back(width);
        else    len.push_back(width + 1);
        i++;
    }
    string symbol;
    for (char c : symRow) {
        if (c != ' ')   symbol.push_back(c);
    }
    vector<vector<string>> a;
    for (int i = 0; i < lines.size() - 1; i++) {
        string row = lines[i];
        vector<string> col;
        int pos = 0;
        for (int width : len) {
            if (pos + width <= row.size())
                col.push_back(row.substr(pos, width));
            else
                col.push_back(row.substr(pos));
            pos += width;
        }
        a.push_back(col);
    }
    int total = 0;
    for (int i = len.size() - 1; i >= 0; i--) {
        int prod = 1, sum = 0;
        for (int j = 0; j <= len[i]; j++) {
            string s = "";
            for (int k = 0; k < a.size(); k++) {
                if (j < a[k][i].size() && a[k][i][j] != ' '){
                    s.push_back(a[k][i][j]);
                }
            }
            if (s.empty())  continue;
            if (symbol[i] == '*')    prod *= stoi(s);
            else    sum += stoi(s);
        }
        if(symbol[i] == '*')    total += prod;
        else    total += sum;
    }
    cout << total << "\n";
}
