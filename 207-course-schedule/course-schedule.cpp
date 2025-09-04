class Solution {
public:
    bool isCycle(int node, unordered_map<int,bool> &visited,
        unordered_map<int,bool> &dfs, unordered_map<int, list<int>>& adj) {

        visited[node] = true;
        dfs[node] = true;

        for(auto neighbor : adj[node]) {
            if(!visited[neighbor]) {
                if(isCycle(neighbor, visited, dfs, adj))  // FIX: pass neighbor
                    return true;
            }
            else if(dfs[neighbor]) {
                return true; // back edge found
            }
        }

        dfs[node] = false; // backtrack
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int , list<int> >adj;

        for(int i = 0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            if(u == v) return false;

            adj[v].push_back(u);
        }

        unordered_map<int,bool> visited(numCourses);
        unordered_map<int,bool> dfs(numCourses);
        for(int i = 0; i<numCourses; i++){
            if(!visited[i]){
                bool checkCycle = isCycle(i , visited , dfs , adj);
                if(checkCycle) return false;
            }
        }

        return true;
    }
};