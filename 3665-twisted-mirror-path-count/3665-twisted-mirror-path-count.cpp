class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> R(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> D(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    R[0][1] = 1;
                    D[1][0] = 1;
                    continue;
                }
                int r = R[i][j], d = D[i][j];
                if (grid[i][j] == 0) {
                    if (i == m - 1 && j == n - 1) return (r + d) % MOD;
                    int f = (r + d) % MOD;
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + f) % MOD;
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + f) % MOD;
                } else {
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + r) % MOD;
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + d) % MOD;
                }
            }
        }
        return 0;
    }
};