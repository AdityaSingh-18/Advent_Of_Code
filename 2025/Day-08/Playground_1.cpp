#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ifstream file("Day08.txt");
    string s;
    vector<vector<int>> a;
    while(getline(file, s)){
        int x = stoi(s.substr(0, s.find(',')));
        int y = stoi(s.substr(s.find(',') + 1, s.find(',', s.find(',') + 1)));
        int z = stoi(s.substr(s.find(',', s.find(',') + 1) + 1));
        a.push_back({x, y, z});
    }
    int n = a.size();
    vector<vector<int>> distance;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            int dx = a[i][0] - a[j][0];
            int dy = a[i][1] - a[j][1];
            int dz = a[i][2] - a[j][2];
            int dis = dx*dx + dy*dy + dz*dz;
            distance.push_back({dis, i, j});
        }
    }
    sort(distance.begin(), distance.end());
    vector<int> circuit(n);
    for (int i = 0; i < n; i++){
        circuit[i] = i;
    }
    int used = 0;
    for (int i = 0; i < distance.size() && used < 1000; i++) {
        int a = distance[i][1], b = distance[i][2];
        int circuit1 = circuit[a], circuit2 = circuit[b];
        used++;
        if (circuit1 == circuit2)   continue;
        for (int j = 0; j < n; j++) {
            if (circuit[j] == circuit2)    circuit[j] = circuit1;
        }
    }
    unordered_map<int, int> countCircuit;
    for (int i = 0; i < n; i++){
        countCircuit[circuit[i]]++;
    }
    vector<int> circuitSize;
    for (auto &c : countCircuit){
        circuitSize.push_back(c.second);
    }
    sort(circuitSize.rbegin(), circuitSize.rend());
    cout << circuitSize[0] * circuitSize[1] * circuitSize[2] << "\n";
}