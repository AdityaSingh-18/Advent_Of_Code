#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<string,int> vertexId;
vector<vector<int>> adj;
int id = 0;

int getId(string &s) {
    if (!vertexId.count(s)) {
        vertexId[s] = id;
        id++;
        adj.resize(id);
    }
    return vertexId[s];
}

int dfs(int u, int target, vector<int> &dp) {
    if (u == target)     return 1;
    if (dp[u] != -1)     return dp[u];
    int ways = 0;
    for (int v : adj[u]){
        ways += dfs(v, target, dp);
    }
    return dp[u] = ways;
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
        while (ss >> con) {
            int v = getId(con);
            adj[u].push_back(v);
        }
    }
    int start = vertexId["you"];
    int target = vertexId["out"];
    vector<int> dp(id, -1);
    int totalWays = dfs(start, target, dp);
    cout << totalWays << "\n";
}
