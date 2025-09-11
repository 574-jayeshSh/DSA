#include<bits/stdc++.h>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int, list<pair<int,int>> >adj;
        for(int i = 0; i<flights.size(); i++){
            int src = flights[i][0];
            int dest = flights[i][1];
            int cost = flights[i][2];

            adj[src].push_back({dest,cost});
        }

        vector<int>costArr(n,INT_MAX);
        set<tuple<int,int,int>> st;
        st.insert({0,src,0});
        costArr[src] = 0;
        
        while(!st.empty()){
            auto [stop , node , nodeCost] = *st.begin();
            st.erase(st.begin());

            
            if( stop > k) continue;
            for(auto it : adj[node]){
                int dest = it.first;
                int cost = it.second;
                if(nodeCost + cost < costArr[dest] && stop <= k){
                    costArr[dest] = nodeCost + cost;
                    st.insert({stop+1,dest ,costArr[dest]});   
                }
            }
            
        }

        if(costArr[dst] == INT_MAX) return -1;

        return costArr[dst];
    }
};