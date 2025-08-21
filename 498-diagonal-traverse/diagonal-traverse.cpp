class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int , vector<int>>p;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                p[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        bool flip = 1;
        for(auto &it : p){
            if(flip){
                reverse(it.second.begin(),it.second.end());
            }
            for(int &nums : it.second){
                ans.push_back(nums);
            }
            flip = !flip;
        }
        return ans;
    }
};