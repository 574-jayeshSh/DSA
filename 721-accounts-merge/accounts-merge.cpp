class Solution {
public:
    int findParent(int node , vector<int>&parent){
        return (node == parent[node]) ? node : (parent[node] = findParent(parent[node],parent));
    }

    void unionRank(int u , int v, vector<int>&parent, vector<int>&rank){
        int s1 = findParent(u,parent);
        int s2 = findParent(v,parent);
        if(s1 == s2) return;
        if(rank[s1] < rank[s2]) parent[s1] = s2;
        else if(rank[s1] > rank[s2]) parent[s2] = s1;
        else{
            parent[s2] = s1;
            rank[s1]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        vector<int> parent(n),rank(n,0);
        for(int i = 0; i<n ; i++) parent[i] = i;



        unordered_map<string , int>adj;
        for(int i = 0; i<n ; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(adj.find(mail) == adj.end()){
                    adj[mail] = i;
                }
                else{
                    unionRank(i, adj[mail] , parent , rank);
                }
            }
        }

        vector<vector<string>> mergeMail(n);
        for(auto it : adj){
            int node = findParent(it.second,parent);
            string mail = it.first;
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i = 0; i<n ; i++){
            if(mergeMail[i].empty()) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto& mail : mergeMail[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};