class Solution {
public:
    long long trip(long long mid , vector<int>& time){
        long long total = 0;
        for(auto i : time){
            total += ( mid / i);
        }
        return total;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        sort(time.begin(), time.end());
        int n = time.size();
        long long low  = 1, high = (long long)  time[n-1] * totalTrips;

        while(low < high){
            long long mid = (low + high)/2;
            if(trip(mid,time) >= totalTrips) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};