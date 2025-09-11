class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        set<pair<int, pair<int,int>>> st;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

        dis[0][0] = 0;
        st.insert({0,{0,0}});

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        while(!st.empty()){
            auto top = *st.begin();
            st.erase(st.begin());

            int diff = top.first;
            int x = top.second.first;
            int y = top.second.second;

            if(x == n-1 && y == m-1) return diff;

            for(int i = 0; i<4; i++){
                int new_i = dx[i]+x;
                int new_j = dy[i]+y;
                if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m ){
                    int newEffort = max(abs(heights[x][y] - heights[new_i][new_j]), diff);
                    if(newEffort < dis[new_i][new_j]){
                        st.erase({dis[new_i][new_j], {new_i, new_j}});
                        dis[new_i][new_j] = newEffort;
                        st.insert({newEffort,{new_i,new_j}});
                    }
                }
            }


        }
        return 0;
    }
};