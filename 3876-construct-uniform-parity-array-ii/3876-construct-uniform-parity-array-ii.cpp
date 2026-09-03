class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if (n == 0) return true;
        vector<int> v = nums1;
        sort(v.begin(), v.end());
        int P = v[0] % 2;
        bool hasParity[2] = {false, false};
        hasParity[v[0] % 2] = true;
        for (int i = 1; i < n; i++) {
            int p = v[i] % 2;
            bool ok = false;
            if (p == P) {
                ok = true;
            } else {
                int need = p ^ P;
                if (hasParity[need]) ok = true;
            }
            if (!ok) return false;
            hasParity[p] = true;
        }
        return true;
    }
};