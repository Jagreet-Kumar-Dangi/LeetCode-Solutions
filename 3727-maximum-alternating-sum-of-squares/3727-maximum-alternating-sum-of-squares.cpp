class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for (int i = 0; i < n; i++) sq[i] = (long long)nums[i] * nums[i];
        sort(sq.begin(), sq.end());
        int plus = (n + 1) / 2;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (i >= n - plus) res += sq[i];
            else res -= sq[i];
        }
        return res;
    }
};