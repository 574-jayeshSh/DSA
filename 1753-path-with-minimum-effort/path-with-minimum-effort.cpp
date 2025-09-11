class Solution {
public:
    struct Cell {
        int x, y, effort;
        bool operator>(const Cell& other) const {
            return effort > other.effort;
        }
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        if (n == 1 && m == 1) return 0;  // single cell

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;

        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
        pq.push({0, 0, 0});

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            Cell cur = pq.top();
            pq.pop();

            int x = cur.x, y = cur.y, diff = cur.effort;

            if (x == n - 1 && y == m - 1) return diff;

            if (diff > dis[x][y]) continue; // stale state, skip

            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
                    int newEffort = max(abs(heights[x][y] - heights[new_x][new_y]), diff);

                    if (newEffort < dis[new_x][new_y]) {
                        dis[new_x][new_y] = newEffort;
                        pq.push({new_x, new_y, newEffort});
                    }
                }
            }
        }

        return 0;
    }
};
