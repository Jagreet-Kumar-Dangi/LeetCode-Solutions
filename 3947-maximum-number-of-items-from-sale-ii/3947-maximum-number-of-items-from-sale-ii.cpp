class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<long long> cnt(n + 2, 0), mult(n + 2, 0);
        long long pmin = LLONG_MAX;
        for (auto& it : items) {
            cnt[it[0]]++;
            pmin = min(pmin, (long long)it[1]);
        }
        for (int f = 1; f <= n; f++) {
            for (int k = f; k <= n; k += f) mult[f] += cnt[k];
        }

        vector<pair<long long, long long>> units;
        for (auto& it : items) {
            long long c = mult[it[0]] - 1;
            long long p = it[1];
            if (c > 0 && p <= 2 * pmin) units.push_back({p, c});
        }
        sort(units.begin(), units.end());

        long long R = budget, x = 0;
        for (auto& [p, c] : units) {
            long long t = min(c, R / p);
            x += t;
            R -= t * p;
            if (t < c) break;
        }
        return 2 * x + R / pmin;
    }
};