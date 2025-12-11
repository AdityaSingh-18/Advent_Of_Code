#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<string,int> vertexId;
vector<vector<int>> adj;
int dp[20000][4];
bool vis[20000][4];
int id = 0;

int getId(string &s) {
    if (!vertexId.count(s)) {
        vertexId[s] = id;
        id++;
        adj.resize(id);
    }
    return vertexId[s];
}

int dfs(int start, int need1, int need2, int target, int mask) {
    if (start == target)    return (mask == 3 ? 1 : 0);
    if (vis[start][mask])    return dp[start][mask];
    vis[start][mask] = true;
    int ways = 0;
    for (int v : adj[start]) {
        int newMask = mask;
        if (v == need1)     newMask |= 1;
        if (v == need2)     newMask |= 2;
        ways += dfs(v, need1, need2, target, newMask);
    }
    return dp[start][mask] = ways;
}

signed main() {
    ifstream file("Day11.txt");
    string s;
    while (getline(file, s)) {
        stringstream ss(s);
        string root;
        ss >> root;
        root.pop_back();
        int u = getId(root);
        string con;
        while (ss >> con){
            int v = getId(con);
            adj[u].push_back(v);
        }
    }
    int start = vertexId["svr"], out = vertexId["out"];
    int need1 = vertexId["dac"], need2 = vertexId["fft"];
    int totalWays = dfs(start, need1, need2, out, 0);
    cout << totalWays << "\n";
}
