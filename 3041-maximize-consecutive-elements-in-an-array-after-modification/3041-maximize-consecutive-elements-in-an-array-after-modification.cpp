class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxV = nums.back() + 2;
        vector<int> dp(maxV + 1, 0);
        int best = 0;
        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
        }
        for (int v = 0; v <= maxV; v++) best = max(best, dp[v]);
        return best;
    }
};