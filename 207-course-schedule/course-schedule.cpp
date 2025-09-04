class Solution {
public:
    bool isCycle(int node, vector<bool> &visited, vector<bool> &dfs, vector<vector<int>> &adj) {
        visited[node] = true;
        dfs[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (isCycle(neighbor, visited, dfs, adj))
                    return true;
            }
            else if (dfs[neighbor]) {
                return true; // back edge found
            }
        }

        dfs[node] = false; // backtrack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> dfs(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && isCycle(i, visited, dfs, adj))
                return false;
        }

        return true;
    }
};
