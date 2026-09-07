class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> last(26, -1);
        vector<long long> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= (int)s.size(); i++) {
            int c = s[i-1] - 'a';
            dp[i] = (2 * dp[i-1]) % MOD;
            if (last[c] != -1) {
                dp[i] = (dp[i] - dp[last[c]-1] + MOD) % MOD;
            }
            last[c] = i;
        }
        return (int)((dp[s.size()] - 1 + MOD) % MOD);
    }
};