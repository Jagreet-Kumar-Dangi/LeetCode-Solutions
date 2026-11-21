class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        vector<int> newParent(parent.begin(), parent.end());
        vector<int> last(26, -1);
        vector<int> saved(n, -1);
        vector<int> idx(n, 0);
        vector<int> order;
        order.reserve(n);

        vector<int> stk;
        stk.push_back(0);
        saved[0] = last[s[0] - 'a'];
        last[s[0] - 'a'] = 0;
        order.push_back(0);

        while (!stk.empty()) {
            int u = stk.back();
            if (idx[u] < (int)children[u].size()) {
                int v = children[u][idx[u]++];
                int c = s[v] - 'a';
                if (last[c] != -1) newParent[v] = last[c];
                saved[v] = last[c];
                last[c] = v;
                order.push_back(v);
                stk.push_back(v);
            } else {
                last[s[u] - 'a'] = saved[u];
                stk.pop_back();
            }
        }

        vector<int> size(n, 1);
        for (int i = n - 1; i >= 1; i--) {
            int x = order[i];
            size[newParent[x]] += size[x];
        }
        return size;
    }
};