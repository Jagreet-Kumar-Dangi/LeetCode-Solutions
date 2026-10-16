class Solution {
public:
    static const long long MOD = 1000000007LL;
    vector<long long> s1, s2, lz;

    void apply(int node, int len, long long v) {
        s2[node] = (s2[node] + 2 * v % MOD * s1[node] % MOD + v * v % MOD * len) % MOD;
        s1[node] = (s1[node] + v * len) % MOD;
        lz[node] = (lz[node] + v) % MOD;
    }

    void push(int node, int l, int r) {
        if (lz[node] != 0) {
            int mid = (l + r) / 2;
            apply(node * 2, mid - l + 1, lz[node]);
            apply(node * 2 + 1, r - mid, lz[node]);
            lz[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, r - l + 1, 1);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);
        s1[node] = (s1[node * 2] + s1[node * 2 + 1]) % MOD;
        s2[node] = (s2[node * 2] + s2[node * 2 + 1]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        s1.assign(4 * n, 0);
        s2.assign(4 * n, 0);
        lz.assign(4 * n, 0);
        vector<int> last(100001, -1);
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            update(1, 0, n - 1, last[nums[j]] + 1, j);
            last[nums[j]] = j;
            ans = (ans + s2[1]) % MOD;
        }
        return (int)ans;
    }
};