class Solution {
public:
    struct cell{
        int time , src;
        bool operator<(const cell& other) const {
            return time > other.time;
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int , list<pair<int,int>> >adj;
        for(int i = 0; i<times.size(); i++){
            int src = times[i][0];
            int tar = times[i][1];
            int time = times[i][2];

            adj[src].push_back({tar,time});
        }

        priority_queue<cell> q;
        q.push({0,k});
        vector<bool> visited(n);
        vector<int> timeArr(n,INT_MAX);
        timeArr[k-1] = 0;

        while(!q.empty()){
            auto [time,node] = q.top();
            q.pop();
            if (visited[node-1]) continue;
            visited[node-1] = true;
            for(auto it : adj[node]){
                int next = it.first;
                int timeToReach = it.second;
                if(it.second + time < timeArr[it.first-1]){
                    timeArr[it.first-1] = it.second + time;
                    q.push({timeArr[it.first - 1] , it.first});
                }
            }
        }
        int tym = INT_MIN;
        for(int i=0; i<n; i++){
            if(visited[i])
                tym = max(tym,timeArr[i]);
        }
        for(int i=0; i<n; i++){
            if(!visited[i])
                return -1;
        }
        return tym;
    }
};