class Solution {
public:

    void dfs(int r , int c , int newColor , int iniColor ,vector<vector<int>>& image,
        vector<vector<int>> &duplicate, int delR[] , int delC[] ){
            duplicate[r][c] = newColor;
            int n = image.size();
            int m = image[0].size();
            for(int i = 0; i<4; i++){
                int nrow = r + delR[i];
                int ncol = c + delC[i];

                if(nrow >= 0 && nrow <n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor && duplicate[nrow][ncol] != newColor){
                    dfs(nrow ,ncol ,newColor ,iniColor ,image ,duplicate ,delR ,delC);
                }
            }
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> duplicate = image;
        int iniColor =image[sr][sc];
        int delRow[] = {-1 , 0 , 1 , 0};
        int delCol[] = {0 , -1 , 0 , 1};

        dfs(sr, sc, color, iniColor, image, duplicate, delRow, delCol);

        return duplicate;
        
    }
};