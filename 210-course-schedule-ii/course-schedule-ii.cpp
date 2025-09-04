#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        // Build adjacency list & indegree
        for (auto &p : edges) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        // Start with courses having no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        ans.reserve(numCourses);  // optimization: avoid reallocations

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int neighbor : adj[node]) {
                if (--indegree[neighbor] == 0)  // combine update + check
                    q.push(neighbor);
            }
        }

        return (ans.size() == numCourses) ? ans : vector<int>{};
    }
};
