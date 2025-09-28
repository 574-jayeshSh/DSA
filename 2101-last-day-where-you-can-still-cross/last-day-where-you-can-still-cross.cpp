class Solution {
public:
    int R;
    int C;
    int dirR[4] = {1,0,-1,0};
    int dirC[4] = {0,1,0,-1};

    bool DFS(vector<vector<int>>&grid  , int i , int j){
        if( i < 0 || i >= R|| j < 0 || j >= C|| grid[i][j] == 1) return false;

        if(i == R-1) return true;

        grid[i][j] = 1;

        for(int k = 0; k<4; k++){
            int new_i = i + dirR[k];
            int new_j = j + dirC[k];
            if(DFS(grid,new_i,new_j)) return true;         
        }
        return false;
    }

    bool check(int mid ,vector<vector<int>>& cells){
        vector<vector<int>>grid(R,vector<int>(C));

        for(int i = 0; i<mid; i++){
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;

            grid[x][y] = 1;
        }

        for(int j  = 0; j<C; j++){
            if(grid[0][j] == 0 && DFS(grid,0,j)) return true;
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        R = row;
        C = col;

        int l = 0, r = cells.size()-1;
        int lastDay = 0;

        while(l <= r){
            int mid =  (l+r)/2;
            if(check(mid,cells)){
                lastDay = mid;
                l = mid+1;
            }
            else{
                r = mid - 1;
            }
        }
        return lastDay;
    }
};