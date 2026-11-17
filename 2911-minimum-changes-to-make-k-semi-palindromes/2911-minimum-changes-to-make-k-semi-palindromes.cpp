class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> divs(n + 1);
        for (int L = 2; L <= n; L++) {
            for (int d = 1; d < L; d++) {
                if (L % d == 0) divs[L].push_back(d);
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int L = j - i + 1;
                int best = INF;
                for (int d : divs[L]) {
                    int m = L / d;
                    int changes = 0;
                    for (int r = 0; r < d; r++) {
                        for (int p = 0; p < m / 2; p++) {
                            if (s[i + r + p * d] != s[i + r + (m - 1 - p) * d]) changes++;
                        }
                    }
                    best = min(best, changes);
                }
                cost[i][j] = best;
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int t = 1; t <= k; t++) {
            for (int j = 1; j <= n; j++) {
                for (int i = t - 1; i < j; i++) {
                    if (dp[t - 1][i] >= INF || cost[i][j - 1] >= INF) continue;
                    dp[t][j] = min(dp[t][j], dp[t - 1][i] + cost[i][j - 1]);
                }
            }
        }
        return dp[k][n];
    }
};