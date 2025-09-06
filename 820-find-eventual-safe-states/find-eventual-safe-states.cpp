class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n, 0);
        vector<vector<int>> revGraph(n);
        set<int> ans;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            outdegree[i] = graph[i].size();
            for (int v : graph[i]) {
                revGraph[v].push_back(i);
            }
            if (outdegree[i] == 0) {
                ans.insert(i);
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int v : revGraph[node]) {
                if (--outdegree[v] == 0) {
                    ans.insert(v);
                    q.push(v);
                }
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};
