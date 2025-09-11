class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)  return -1;
        if(n == 1 && grid[0][0] == 0) return 1;   

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<vector<int>>q;
        
        q.push({0,0,1});

        visited[0][0] = 1;

        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int i = front[0];
            int j = front[1];
            int cnt = front[2];

            if(i == n-1 && j == n-1) return cnt;

            for (int k = 0; k < 8; k++) {
                int new_i = i + dx[k];
                int new_j = j + dy[k];

                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n &&
                 !visited[new_i][new_j] && grid[new_i][new_j] == 0) {
                    visited[new_i][new_j] = 1;
                    q.push({new_i,new_j,cnt+1});
                    
                }
                
            }
            
        }

        return -1;
    }
};