class Solution {
public:
    double time(int speed ,vector<int>& dist){
        double t = 0;
        for(int i = 0; i<dist.size(); i++){
            if(i != dist.size()-1){
                t += ceil((double)dist[i]/speed);
            }
            else t += (double)dist[i]/speed;
        }
        return t;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int right = 1000000000;
        int left = 1;
        int answer = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(hour >= time(mid , dist)){
                answer = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return answer == 0 ? -1 : answer;

    }
};