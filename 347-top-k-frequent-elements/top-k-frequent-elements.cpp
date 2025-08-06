class Solution {
public:
    typedef pair<int ,int> P;

    struct lambda{
        bool operator()(P &p1 ,P&p2){
            return p1.second < p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<P , vector<P> , lambda > pq;
        unordered_map<int,int> mpp;

        for(int ch: nums){
            mpp[ch]++;
        }

        for(auto &it: mpp){
           pq.push({it.first ,it.second});
        }
        vector<int> ans;
        while(k-- && !pq.empty()){
           P temp = pq.top();
           pq.pop();

           ans.push_back(temp.first);
        }
        return ans;
    }
};