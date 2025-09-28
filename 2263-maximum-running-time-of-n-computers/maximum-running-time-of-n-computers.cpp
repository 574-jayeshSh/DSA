class Solution {
public:
    bool check(long long time ,vector<int>& batteries , int n){
        long long sum = 0;
        for(int i = 0; i<batteries.size(); i++){
            sum += min((long long)batteries[i], time);
            if(sum >= n*time) return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = *min_element(batteries.begin(), batteries.end());
        long long sum = 0;
        for(int i = 0; i<batteries.size(); i++){
            sum += batteries[i];
        }
        long long right = sum/n;
        long long answer = 0;
        while(left <= right){
            long long mid = (left+right) / 2;

            long long timeTakenBYComputer = n*mid;
            if(check(mid , batteries, n)){
                answer = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return answer;

    }
};