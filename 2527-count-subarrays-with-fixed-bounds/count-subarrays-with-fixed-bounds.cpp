class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    
        int minInd = -1, maxInd = -1;
        int culprit = -1;
        long long ans = 0;

        for(int i = 0; i<nums.size();i++){
            if(nums[i] > maxK || nums[i] < minK){
                culprit = i;
            }

            if (nums[i] == maxK) maxInd = i;
            if (nums[i] == minK) minInd = i;
            int mini = min(maxInd , minInd);

            int temp = mini - culprit ;

            ans += (temp <= 0) ? 0 : temp;
        }
        return ans ;
    }
};