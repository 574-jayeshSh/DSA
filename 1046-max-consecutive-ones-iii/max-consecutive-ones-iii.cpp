class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 , r = 0;
        int n = nums.size();
        int maxLen = 0;
        int cnt = 0;
        while(r != n){
           if(nums[r] == 0){
                    cnt++;
            }
                
            if(cnt > k){
                if(nums[l] == 0){
                    cnt--;
                }
                l++;
            }
            
            int len = r - l + 1;
            maxLen = max(maxLen,len);

            r++;
        }
        return maxLen;
    }
};