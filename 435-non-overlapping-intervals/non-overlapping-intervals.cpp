class Solution {
public:
    static bool comparator(vector<int> &a, vector<int> &b) {
        return a[1] < b[1]; 
    }
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end() , comparator);
        int cnt = 1;
        int lastEndTime = arr[0][1];
        for(int i = 0; i<arr.size(); i++){
            if(arr[i][0] >= lastEndTime){
                cnt++;
                lastEndTime = arr[i][1];
            }
        }
        return (arr.size() - cnt);
    }
};