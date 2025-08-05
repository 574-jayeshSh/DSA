class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 2 * k + 1;
        vector<int> pSum(n, -1);

        if (n < len) return pSum;

        long long sum = 0;
        int l = 0, r = 2 * k;
        int i = k;

        for (int j = l; j <= r; j++) {
            sum += nums[j];
        }

        pSum[i++] = sum / len;
        r++;

        while (r < n) {
            sum = sum + nums[r] - nums[l];
            pSum[i++] = sum / len;
            l++;
            r++;
        }

        return pSum;
    }
};
