class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        // traverese through array and add ans ;
        for(int i = 0; i < nums.size(); i++){
            if(!dq.empty() && dq.front() <= i-k){       // maintaining the sliding window
                dq.pop_front();
            }      
            while(!dq.empty() && nums[dq.back()] <= nums[i]){     // maintaining monotonic stack
                dq.pop_back();
            }
            dq.push_back(i);

            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};