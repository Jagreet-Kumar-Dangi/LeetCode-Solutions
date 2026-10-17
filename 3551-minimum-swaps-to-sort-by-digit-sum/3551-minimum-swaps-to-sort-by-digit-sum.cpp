class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        auto ds = [](int x) {
            int s = 0;
            while (x > 0) { s += x % 10; x /= 10; }
            return s;
        };

        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            int da = ds(nums[a]), db = ds(nums[b]);
            if (da != db) return da < db;
            return nums[a] < nums[b];
        });

        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || idx[i] == i) continue;
            int len = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = idx[j];
                len++;
            }
            swaps += len - 1;
        }
        return swaps;
    }
};