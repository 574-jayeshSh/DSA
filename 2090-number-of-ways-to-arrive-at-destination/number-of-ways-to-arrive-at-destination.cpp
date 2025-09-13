class Solution {
public:
    const int MOD = 1e9 + 7;
    struct cell{
        long long time , src;
        bool operator<(const cell& other) const {
            return time > other.time;
        }
    };

    long long shortestPath(vector<long long>& timeArr,priority_queue<cell>&q,unordered_map<int , 
        list<pair<int,int>> >&adj,vector<int>& ways){
        while(!q.empty()){
            auto [tym , node] = q.top();
            q.pop();
            
            if (tym > timeArr[node]) continue;
            for(auto it : adj[node]){
                long long nei = it.first;
                long long time = it.second;
                if(tym + time < timeArr[nei]){
                    timeArr[nei] = tym + time;
                    ways[nei] = ways[node];
                    q.push({timeArr[nei],nei});
                }
                else if(tym + time == timeArr[nei]){
                    ways[nei] = (ways[nei] + ways[node]) % MOD;

                }
            }
        }
        
        return ways[timeArr.size()-1]%MOD;

    }
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int , list<pair<int,int>> >adj;
        for(int i = 0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];

            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }

        vector<long long> timeArr(n,LLONG_MAX);
        vector<int> ways(n,0);
        priority_queue<cell>q;
        q.push({0,0});
        timeArr[0] = 0;
        ways[0] = 1;

        int noOfPath = shortestPath(timeArr,q,adj,ways);

        return noOfPath;
    }
};