class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour <= n - 1) return -1;

        int left = 1, right = 1e7, answer = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            double t = 0;

            for(int i = 0; i < n; i++) {
                if(i != n - 1)
                    t += (dist[i] + mid - 1) / mid; // integer ceil trick
                else
                    t += (double)dist[i] / mid;
            }

            if(t <= hour) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
