class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int s = nums[0];
        bool fwd = true, rev = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (i + s) % n) fwd = false;
            if (nums[i] != (((s - i) % n) + n) % n) rev = false;
        }
        long long best = LLONG_MAX;
        if (fwd) {
            int m = (n - s) % n;
            long long c = (m == 0) ? 0 : min<long long>(m, s + 2);
            best = min(best, c);
        }
        if (rev) {
            long long c1 = 1 + (n - s - 1) % n;
            long long c2 = 1 + (s + 1) % n;
            best = min(best, min(c1, c2));
        }
        return best == LLONG_MAX ? -1 : (int)best;
    }
};