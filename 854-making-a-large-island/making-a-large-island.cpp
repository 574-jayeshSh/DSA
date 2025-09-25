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

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> parent(n * n), rank(n * n, 0), size(n * n, 1);
        for (int i = 0; i < n * n; i++) parent[i] = i;

        int dRow[4] = {0, 1, 0, -1};
        int dCol[4] = {-1, 0, 1, 0};

        // Step 1: Union all adjacent 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int node = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dRow[k], nj = j + dCol[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            int neighbor = ni * n + nj;
                            unionRank(node, neighbor, parent, rank);
                        }
                    }
                }
            }
        }

        // Step 2: Map root → island size
        unordered_map<int, int> islandSize;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int root = findParent(i * n + j, parent);
                    islandSize[root]++;
                }
            }
        }

        // Step 3: Try flipping each 0 and check max area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighborIslands;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dRow[k], nj = j + dCol[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            int root = findParent(ni * n + nj, parent);
                            neighborIslands.insert(root);
                        }
                    }
                    int area = 1; // flipped cell
                    for (int root : neighborIslands) {
                        area += islandSize[root];
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }

        // Edge case: entire grid is 1s already
        if (maxArea == 0) {
            for (auto& [_, area] : islandSize) {
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
