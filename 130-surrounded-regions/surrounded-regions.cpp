class Solution {
public:
    void dfs(int r , int c ,vector<vector<char>>& board,vector<vector<int>> &visited,
         int delR[] , int delC[] ){
            visited[r][c] = 1;
            
            int n = board.size();
            int m = board[0].size();
           
            for(int i = 0; i<4; i++){
                int nrow = r + delR[i];
                int ncol = c + delC[i];

                if(nrow >= 0 && nrow <n && ncol >= 0 && ncol < m &&
                board[nrow][ncol] == 'O' && visited[nrow][ncol] != 1){
                    dfs(nrow ,ncol ,board ,visited ,delR ,delC);
                }
            }
        
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        
        int delRow[] = {-1 , 0 , 1 , 0};
        int delCol[] = {0 , -1 , 0 , 1};
        // boundary row traversal;
       for(int j = 0; j<m; j++){
         if(!visited[0][j] && board[0][j] == 'O'){
            dfs(0,j,board,visited,delRow,delCol);
         }
         if(!visited[n-1][j] && board[n-1][j] == 'O'){
            dfs(n-1,j,board,visited,delRow,delCol);
         }
       }
        // boundaray col traversal
       for(int i = 0; i<n; i++){
         if(!visited[i][0] && board[i][0] == 'O'){
            dfs(i,0,board,visited,delRow,delCol);
         }

         if(!visited[i][m-1] && board[i][m-1] == 'O'){
            dfs(i,m-1,board,visited,delRow,delCol);
         }
       }

       //changing 0->X

       for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(visited[i][j] != 1 && board[i][j] == 'O' ){
                board[i][j] = 'X';
            }
        }
       }
    }
};