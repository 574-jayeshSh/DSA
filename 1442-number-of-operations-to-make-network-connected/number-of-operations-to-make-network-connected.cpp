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

    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<int> parent(n), rank(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
            rank[i] = 1;
        }

        int count = 0;
        int skip = 0;
        for(auto &e : connections){
            int x = e[0] , y = e[1];
            if(find(x,parent) != find(y,parent)){
                unite(x,y,parent,rank);
                if(count++ == n-1) break;
            }
            else{
                skip++;
                continue;
            }
        }
        
        int components = 0;
        for(int i = 0; i<n; i++){
            if(find(i,parent) == i) components++;
        }
        return components - 1 ;
    }
};