class Solution {
public:
    int n, k;
    vector<int> matArr;
    vector<int> cntArr;
    vector<int> nums;

    void buildLeaf(int node, int idx) {
        int a = nums[idx] % k;
        for (int i = 0; i < k; i++) matArr[node * k + i] = (i * a) % k;
        for (int i = 0; i < k; i++)
            for (int x = 0; x < k; x++)
                cntArr[node * k * k + i * k + x] = (matArr[node * k + i] == x) ? 1 : 0;
    }

    void merge(int node, int left, int right) {
        for (int i = 0; i < k; i++) {
            int mid = matArr[left * k + i];
            matArr[node * k + i] = matArr[right * k + mid];
            for (int x = 0; x < k; x++) {
                cntArr[node * k * k + i * k + x] =
                    cntArr[left * k * k + i * k + x] + cntArr[right * k * k + mid * k + x];
            }
        }
    }

    void build(int node, int l, int r) {
        if (l == r) { buildLeaf(node, l); return; }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        merge(node, node * 2, node * 2 + 1);
    }

    void update(int node, int l, int r, int idx) {
        if (l == r) { buildLeaf(node, l); return; }
        int mid = (l + r) / 2;
        if (idx <= mid) update(node * 2, l, mid, idx);
        else update(node * 2 + 1, mid + 1, r, idx);
        merge(node, node * 2, node * 2 + 1);
    }

    void queryCollect(int node, int l, int r, int ql, int qr, vector<int>& segs) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { segs.push_back(node); return; }
        int mid = (l + r) / 2;
        queryCollect(node * 2, l, mid, ql, qr, segs);
        queryCollect(node * 2 + 1, mid + 1, r, ql, qr, segs);
    }

    vector<int> resultArray(vector<int>& nums_, int k_, vector<vector<int>>& queries) {
        nums = nums_;
        k = k_;
        n = nums.size();
        matArr.assign(4 * n * k, 0);
        cntArr.assign(4 * n * k * k, 0);
        build(1, 0, n - 1);

        vector<int> result;
        for (auto& q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            nums[index] = value;
            update(1, 0, n - 1, index);

            vector<int> segs;
            queryCollect(1, 0, n - 1, start, n - 1, segs);

            int cur = 1 % k;
            vector<long long> cntRes(k, 0);
            for (int node : segs) {
                for (int xx = 0; xx < k; xx++) {
                    cntRes[xx] += cntArr[node * k * k + cur * k + xx];
                }
                cur = matArr[node * k + cur];
            }
            result.push_back((int)cntRes[x]);
        }
        return result;
        
    }
};