class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> temp;
        vector<int> ans;

        for(int i = nums.size()-1; i >= 0; i--){
            int index = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
            ans.push_back(index);
            temp.insert(temp.begin() + index , nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};