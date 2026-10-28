class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        dp[0][0][grid[0][0]] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int v = grid[i][j];
                for (int x = 0; x < 1024; x++) {
                    bool ok = false;
                    if (i > 0 && dp[i - 1][j][x ^ v]) ok = true;
                    if (!ok && j > 0 && dp[i][j - 1][x ^ v]) ok = true;
                    if (ok) dp[i][j][x] = 1;
                }
            }
        }
        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1][n - 1][x]) return x;
        }
        return -1;
    }
};