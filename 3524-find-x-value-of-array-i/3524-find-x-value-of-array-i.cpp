class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
         vector<long long> result(k, 0);
        vector<long long> dp(k, 0);
        for (int num : nums) {
            int x = num % k;
            vector<long long> newDp(k, 0);
            for (int u = 0; u < k; u++) {
                if (dp[u] > 0) {
                    int v = (u * x) % k;
                    newDp[v] += dp[u];
                }
            }
            newDp[x % k] += 1;
            dp = newDp;
            for (int v = 0; v < k; v++) {
                result[v] += dp[v];
            }
        }
        return result;
    }
};