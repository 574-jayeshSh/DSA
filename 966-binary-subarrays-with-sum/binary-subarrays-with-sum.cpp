class Solution {
public:
    int computeGoal(vector<int>& nums, int goal) {
        
        if(goal < 0) return 0;
        int l = 0 ,r = 0;
        int n = nums.size();
        int cnt = 0;
        int sum = 0;
        while(r < n){
            sum += nums[r];
            while( sum > goal){
                sum -= nums[l];
                l++;
            }
            
        
            cnt += (r-l+1);
            r++;
        }
        
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return (computeGoal(nums,goal) - computeGoal(nums,goal-1));}
};