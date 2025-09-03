class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f = INT_MAX;
        int s = INT_MAX;
        

       for(int k = 0; k<nums.size(); k++){
            if(nums[k] <= f){
                f = nums[k];
            }

            else if(nums[k] <= s)  s = nums[k];

            else if( nums[k] > s && nums[k] > f) return true;
        }
        return false;

    }
};