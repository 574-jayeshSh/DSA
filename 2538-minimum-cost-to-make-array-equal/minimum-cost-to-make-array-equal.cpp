class Solution {
public:

    long long findCost(vector<int>& nums, vector<int>& cost, int num){
        long long c = 0;
        for(int i = 0; i<nums.size(); i++){
            c += 1LL * abs((long long)num - nums[i]) * cost[i];
        }
        return c;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long answer = LLONG_MAX;
        int low  = *min_element(nums.begin(),nums.end());
        int high  = *max_element(nums.begin(),nums.end());

        while(low <= high){
            int mid = (low + high)/2;

            long long cost1 = findCost(nums,cost,mid);
            long long cost2 = findCost(nums,cost,mid+1);

            answer = min(cost1, cost2);

            if(cost1 < cost2) high = mid - 1;
            else low = mid + 1;
        }

        return answer;
        
    }
};