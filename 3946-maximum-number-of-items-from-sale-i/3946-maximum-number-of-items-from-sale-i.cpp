class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> bonus(n, 0);
        int pmin = INT_MAX;
        for (int i = 0; i < n; i++) {
            pmin = min(pmin, items[i][1]);
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) bonus[i]++;
            }
        }

        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int p = items[i][1];
            int val = 1 + bonus[i];
            for (int b = budget; b >= p; b--) {
                dp[b] = max(dp[b], dp[b - p] + val);
            }
        }

        int best = 0;
        for (int b = 0; b <= budget; b++) {
            best = max(best, dp[b] + (budget - b) / pmin);
        }
        return best;
    }
};