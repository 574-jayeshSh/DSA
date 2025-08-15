class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int>mpp;
        for(int i = 0; i<nums.size(); i++){
            int scndDigit = target - nums[i];
            if(mpp.count(scndDigit)){
                return {i,mpp[scndDigit]};
            }
            mpp[nums[i]] = i;
        }
        return {-1,-1};
    }
};