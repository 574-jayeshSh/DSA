class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
         
        int evenSum = 0; 
        for( auto it : nums){
            if(it % 2 == 0) evenSum += it;
        } 
       
        int n = queries.size();
        vector<int>ans;

        for(int i = 0; i<n; i++){
            int ind = queries[i][1];
            int val = queries[i][0];

            if(nums[ind] % 2 == 0){
                evenSum -= nums[ind];
            }

            nums[ind] += val;

            if(nums[ind] % 2 == 0){
                evenSum += nums[ind];
            }

            ans.push_back(evenSum);
        }
        return ans;
    }
};