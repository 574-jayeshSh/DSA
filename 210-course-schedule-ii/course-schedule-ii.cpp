#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int node,
               unordered_map<int, bool>& visited,
               unordered_map<int, bool>& dfsvisited,
               unordered_map<int, list<int>>& adj,
               vector<int>& ans) {
        
        visited[node] = true;
        dfsvisited[node] = true;

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (check(neighbor, visited, dfsvisited, adj, ans)) {
                    return true; // cycle found
                }
            } 
            else if (dfsvisited[neighbor]) {
                return true; // cycle detected
            }
        }

        dfsvisited[node] = false; // backtrack
        ans.push_back(node);      // add to topo order
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;

        // build adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[b].push_back(a);
        }

        vector<int> ans;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsvisited;

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (check(i, visited, dfsvisited, adj, ans)) {
                    return {}; // cycle → no valid order
                }
            }
        }

        reverse(ans.begin(), ans.end()); // reverse for correct topo order
        return ans;
    }
};
