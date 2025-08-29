class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for(auto it : nums){
            totalSum += it;
        }

        int cummSum = 0;
        for(int i = 0 ; i<nums.size(); i++){
            int rightSum = totalSum - cummSum - nums[i];
            if(rightSum == cummSum) return i;
            cummSum += nums[i];
        }

        return -1;
    }
};