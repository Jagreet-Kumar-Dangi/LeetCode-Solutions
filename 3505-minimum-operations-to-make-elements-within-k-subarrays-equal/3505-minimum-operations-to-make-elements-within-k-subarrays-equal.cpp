class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int m = n - x + 1;
        vector<long long> cost(m);

        multiset<int> lo, hi;
        long long sumLo = 0, sumHi = 0;

        auto rebalance = [&]() {
            int target = (lo.size() + hi.size() + 1) / 2;
            while ((int)lo.size() > target) {
                auto it = prev(lo.end());
                int v = *it;
                lo.erase(it);
                sumLo -= v;
                hi.insert(v);
                sumHi += v;
            }
            while ((int)lo.size() < target && !hi.empty()) {
                auto it = hi.begin();
                int v = *it;
                hi.erase(it);
                sumHi -= v;
                lo.insert(v);
                sumLo += v;
            }
        };

        auto add = [&](int v) {
            if (lo.empty() || v <= *lo.rbegin()) {
                lo.insert(v);
                sumLo += v;
            } else {
                hi.insert(v);
                sumHi += v;
            }
            rebalance();
        };

        auto remove = [&](int v) {
            if (!lo.empty() && v <= *lo.rbegin()) {
                lo.erase(lo.find(v));
                sumLo -= v;
            } else {
                hi.erase(hi.find(v));
                sumHi -= v;
            }
            rebalance();
        };

        auto calc = [&]() {
            long long med = *lo.rbegin();
            return med * (long long)lo.size() - sumLo + sumHi - med * (long long)hi.size();
        };

        for (int i = 0; i < x; i++) add(nums[i]);
        cost[0] = calc();
        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);
            cost[i - x + 1] = calc();
        }

        const long long INF = LLONG_MAX / 4;
        vector<long long> prevDp(n + 1, 0), curDp(n + 1, INF);
        for (int j = 1; j <= k; j++) {
            fill(curDp.begin(), curDp.end(), INF);
            for (int i = x; i <= n; i++) {
                curDp[i] = curDp[i - 1];
                if (prevDp[i - x] < INF) {
                    curDp[i] = min(curDp[i], prevDp[i - x] + cost[i - x]);
                }
            }
            swap(prevDp, curDp);
        }
        return prevDp[n];
    }
};