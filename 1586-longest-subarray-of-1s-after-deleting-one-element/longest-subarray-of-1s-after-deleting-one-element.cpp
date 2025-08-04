class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int k = 1;  // We can delete at most one 0
        int maxLen = 0;
        while (j < nums.size()) {
            if (nums[j] == 0) k--;

            while (k < 0) {
                if (nums[i] == 0) k++;
                i++;
            }
            maxLen = max(maxLen, j - i); 
            j++;
        }

        return maxLen;  // subtract one for the deleted element
    }
};

