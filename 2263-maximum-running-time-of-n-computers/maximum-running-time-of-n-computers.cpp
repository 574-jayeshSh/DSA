class Solution {
public:
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
            long long total = 0;
            for(int b : batteries) total += min((long long)b, mid);

            if(n*mid <= total){
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