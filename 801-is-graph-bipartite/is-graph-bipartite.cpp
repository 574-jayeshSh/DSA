class Solution {
public:
    char toggle(char c) {
        if (c == 'G') return 'R';
        else if (c == 'R') return 'G';
        else return c; // if something else is passed, return as is
    }

    bool bfs(vector<vector<int>> &adj, unordered_map<int ,pair<bool,char>> &visited , int node ){
        queue<int> q;
        q.push(node);
        visited[node] = {true,'G'};
      
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto j : adj[frontNode]){
                if(!visited[j].first){
                    q.push(j);
                   visited[j] = {true, toggle(visited[frontNode].second)}; 
                }
                else if( visited[j].second == visited[frontNode].second ){
                    return false;
                }
            }
        }
        return true;
    }

    
    bool isBipartite(vector<vector<int>>& adj) {
        
        int n = adj.size();

        unordered_map<int ,pair<bool,char>> visited;

        for(int i = 0; i<n; i++){
            if(!visited[i].first){
                if(!bfs(adj,visited,i)) return false;
            }
        }

        return true;
    }
};