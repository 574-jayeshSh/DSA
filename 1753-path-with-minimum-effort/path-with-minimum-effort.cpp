class Solution {
public:
    struct Cell {
        int x,y,effort;
        bool operator>(const Cell& o) const { return effort > o.effort; }
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        if(n==1 && m==1) return 0;

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0]=0;
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
        pq.push({0,0,0});

        int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
        while(!pq.empty()){
            auto cur=pq.top(); pq.pop();
            if(cur.x==n-1 && cur.y==m-1) return cur.effort;
            if(cur.effort>dis[cur.x][cur.y]) continue;
            for(int k=0;k<4;k++){
                int nx=cur.x+dx[k], ny=cur.y+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    int ne=max(abs(heights[cur.x][cur.y]-heights[nx][ny]),cur.effort);
                    if(ne<dis[nx][ny]){
                        dis[nx][ny]=ne;
                        pq.push({nx,ny,ne});
                    }
                }
            }
        }
        return 0;
    }
};
