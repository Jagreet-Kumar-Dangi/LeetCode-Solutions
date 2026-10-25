class Solution {
public:
    int m, n;

    void flood(vector<vector<int>>& grid, int sr, int sc) {
        stack<pair<int,int>> stk;
        grid[sr][sc] = 1;
        stk.push({sr, sc});
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!stk.empty()) {
            auto [r, c] = stk.top(); stk.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    stk.push({nr, nc});
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) flood(grid, i, 0);
            if (grid[i][n - 1] == 0) flood(grid, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0) flood(grid, 0, j);
            if (grid[m - 1][j] == 0) flood(grid, m - 1, j);
        }

        int count = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    flood(grid, i, j);
                }
            }
        }
        return count;
    }
};