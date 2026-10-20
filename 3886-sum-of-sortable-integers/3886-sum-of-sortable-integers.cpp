class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            bool ok = true;
            int prevMax = INT_MIN;
            for (int s = 0; s < n && ok; s += k) {
                int desc = 0;
                int mn = INT_MAX, mx = INT_MIN;
                for (int i = 0; i < k; i++) {
                    int cur = nums[s + i];
                    int nxt = nums[s + (i + 1) % k];
                    if (cur > nxt) desc++;
                    mn = min(mn, cur);
                    mx = max(mx, cur);
                }
                if (desc > 1 || mn < prevMax) ok = false;
                prevMax = mx;
            }
            if (ok) total += k;
        }
        return (int)total;
    }
};