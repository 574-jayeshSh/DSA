class Solution {
public:
    void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
             vector<vector<int>> &adj, vector<bool> &vis, vector<vector<int>> &result) {
        vis[node] = true;
        disc[node] = low[node] = timer++;
        for (auto nbr : adj[node]) {
            if (nbr == parent) continue;
            if (!vis[nbr]) {
                dfs(nbr, node, timer, disc, low, adj, vis, result);
                low[node] = min(low[node], low[nbr]);
                if (low[nbr] > disc[node]) result.push_back({node, nbr});
            } else {
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto &c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        int timer = 0;
        vector<int> disc(n, -1), low(n, -1);
        vector<bool> vis(n, false);
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i, -1, timer, disc, low, adj, vis, result);
        }
        return result;
    }
};
