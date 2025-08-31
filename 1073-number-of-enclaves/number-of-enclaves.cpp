class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));
        int cnt = 0;
        queue<pair<int,int>> q;
         for (int j = 0; j < m; j++) {
            if (!visited[0][j] && grid[0][j] == 1) {
                q.push({0,j});
                visited[0][j] = 1;
            }
            if (!visited[n-1][j] && grid[n-1][j] == 1) {
                q.push({n-1,j});
                visited[n-1][j] = 1;
            }
        }

        // Boundary column traversal
        for (int i = 0; i < n; i++) {
            if (!visited[i][0] && grid[i][0] == 1) {
                q.push({i,0});
                visited[i][0] = 1;
            }
            if (!visited[i][m - 1] && grid[i][m - 1] == 1) {
                q.push({i,m-1});
                visited[i][m-1] = 1; 
            }
        }
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();

            

            for (int i = 0; i < 4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = 1;
                }
            }

        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;

    }
};