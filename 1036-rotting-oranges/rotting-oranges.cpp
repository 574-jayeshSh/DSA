class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        // {{r,c},t}
        queue<pair< pair<int,int> , int>>q;

        //mark rotten fruits and empty cell;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 2;
                    q.push({ {i,j}, 0 });
                }
                else{
                    visited[i][j] = 0;
                }
            }
        }

        int tm = 0;

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tym = q.front().second;
            q.pop();

            tm = max(tm , tym);

            for(int i = 0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1 ){
                    
                    q.push({{nrow , ncol} , tym + 1});
                    visited[nrow][ncol] = 2;
                }
                    
            }
        }
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(visited[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return tm;
        
    }
};