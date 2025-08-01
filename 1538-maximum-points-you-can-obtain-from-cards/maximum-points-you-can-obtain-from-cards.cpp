class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int leftSum  = 0, rightSum = 0, maxSum = 0;
        for(int i = 0; i<=k-1; i++){
            leftSum += nums[i];
            maxSum = leftSum;
        }

        int rightInd = nums.size()-1;

        for(int i = k-1; i>=0; i--){
            leftSum -= nums[i];
            rightSum += nums[rightInd];
            rightInd-- ;
            maxSum = max(maxSum,(leftSum + rightSum));
        }
        return maxSum;
    }
};