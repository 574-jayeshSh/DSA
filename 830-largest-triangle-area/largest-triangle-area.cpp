class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0.0;
        for(int i = 0; i<points.size() - 2; i++){
            for(int j = i+1; j<points.size() - 1; j++){
                for(int k = j+1; k<points.size(); k++){
                    double x1 = points[i][0] , y1 = points[i][1];
                    double x2 = points[j][0] , y2 = points[j][1];
                    double x3 = points[k][0] , y3 = points[k][1];
                    double area = 0.5 * abs((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (-y2 + y1)));
                    ans = max(ans , area);
                }
            }
        }
        return ans;
    }
};