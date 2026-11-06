class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int q = queries.size();
        vector<int> order(q);
        for (int i = 0; i < q; i++) order[i] = i;
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        vector<int> cnt(n + 1, 0);
        int active = 0;
        int lo = 0, hi = 0;
        int m = logs.size();
        vector<int> res(q);

        for (int idx : order) {
            int t = queries[idx];
            while (hi < m && logs[hi][1] <= t) {
                if (cnt[logs[hi][0]]++ == 0) active++;
                hi++;
            }
            while (lo < hi && logs[lo][1] < t - x) {
                if (--cnt[logs[lo][0]] == 0) active--;
                lo++;
            }
            res[idx] = n - active;
        }
        return res;
    }
};