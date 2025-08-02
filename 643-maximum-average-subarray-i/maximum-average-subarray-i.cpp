#include <vector>
#include <cfloat>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = 0; 
        double sum = 0;
        double maxAvg = -DBL_MAX;

        while(r < nums.size()) {
            sum += nums[r];

            if ((r - l + 1) == k) {
                maxAvg = max(maxAvg, sum / k);
                sum -= nums[l];
                l++;
            }

            r++;
        }

        return maxAvg;
    }
};
