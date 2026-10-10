class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int maxD = 0;
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxD = max(maxD, diff[i]);
        }

        vector<long long> cnt(maxD + 1, 0);
        for (int d : diff) cnt[d]++;

        long long k = (long long)k1 + k2;
        for (int d = maxD; d >= 1 && k > 0; d--) {
            if (cnt[d] == 0) continue;
            if (k >= cnt[d]) {
                k -= cnt[d];
                cnt[d - 1] += cnt[d];
                cnt[d] = 0;
            } else {
                cnt[d - 1] += k;
                cnt[d] -= k;
                k = 0;
            }
        }

        long long res = 0;
        for (int d = 1; d <= maxD; d++) {
            res += cnt[d] * (long long)d * d;
        }
        return res;
    }
};