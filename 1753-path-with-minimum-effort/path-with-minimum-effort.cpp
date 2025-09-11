class Solution {
public:
    struct Cell {
        int x, y, effort;
    };

    struct cmp {
        bool operator()(const Cell& a, const Cell& b) const {
            if (a.effort == b.effort) {
                if (a.x == b.x) return a.y < b.y;
                return a.x < b.x;
            }
            return a.effort < b.effort;
        }
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        if (n == 1 && m == 1) return 0;  // only one cell

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;

        set<Cell, cmp> st;
        st.insert({0, 0, 0});  // (x=0, y=0, effort=0)

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!st.empty()) {
            Cell cur = *st.begin();
            st.erase(st.begin());

            int x = cur.x, y = cur.y, diff = cur.effort;

            if (x == n - 1 && y == m - 1) return diff;

            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
                    int newEffort = max(abs(heights[x][y] - heights[new_x][new_y]), diff);

                    if (newEffort < dis[new_x][new_y]) {
                        st.erase({new_x, new_y, dis[new_x][new_y]}); // remove old state
                        dis[new_x][new_y] = newEffort;
                        st.insert({new_x, new_y, newEffort});
                    }
                }
            }
        }

        return 0; // fallback (should never hit)
    }
};
