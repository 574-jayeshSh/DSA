class Solution {
public:
    int find(int i, vector<int> &parent){
        return (parent[i] == i) ? i : (parent[i] = find(parent[i],parent));
    }
    
    void unite(int x , int y , vector<int> &parent, vector<int> &rank){
        int s1 = find(x,parent) , s2 = find(y,parent);

        if(s1 != s2){
            if(rank[s1] < rank[s2]) parent[s1] = s2;
            else if(rank[s2] < rank[s1]) parent[s2] = s1;
            else parent[s2] = s1, rank[s1]++;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int , pair<int,int>> mappedInd;

        for(int i = 0; i<stones.size(); i++){
            mappedInd[i] = {stones[i][0],stones[i][1]};
        }
        int cnt = 0;
        vector<int> parent(n), rank(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i = 0; i<stones.size() - 1; i++){
            for(int j = 1; j<stones.size(); j++){
                if(mappedInd[i].first == mappedInd[j].first || mappedInd[i].second == mappedInd[j].second){
                    if(find(i,parent) != find(j,parent)){
                        unite(i,j,parent,rank);
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};