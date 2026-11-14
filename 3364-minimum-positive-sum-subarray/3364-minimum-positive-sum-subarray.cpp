class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];
        int best = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int len = l; len <= r && i + len <= n; len++) {
                int s = pre[i + len] - pre[i];
                if (s > 0) best = min(best, s);
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};