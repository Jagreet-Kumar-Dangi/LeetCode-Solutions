class Solution {
public:
    int n, LOG = 16, timer = 0;
    vector<int> tin, tout, depth, bit;
    vector<vector<int>> up;

    void upd(int i, int v) {
        for (; i <= n + 1; i += i & -i) bit[i] ^= v;
    }
    int qry(int i) {
        int r = 0;
        for (; i > 0; i -= i & -i) r ^= bit[i];
        return r;
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int k = 0; k < LOG; k++) if (diff >> k & 1) a = up[k][a];
        if (a == b) return a;
        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    }

    vector<bool> palindromePath(int n_, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = n_;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        bit.assign(n + 3, 0);
        up.assign(LOG, vector<int>(n, 0));

        vector<int> idx(n, 0);
        vector<int> stk;
        stk.push_back(0);
        up[0][0] = 0;
        tin[0] = ++timer;
        while (!stk.empty()) {
            int u = stk.back();
            if (idx[u] < (int)adj[u].size()) {
                int v = adj[u][idx[u]++];
                if (v == up[0][u] && u != 0) continue;
                if (v == up[0][u] && u == 0 && false) continue;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                tin[v] = ++timer;
                stk.push_back(v);
            } else {
                tout[u] = timer;
                stk.pop_back();
            }
        }
        for (int k = 1; k < LOG; k++)
            for (int v = 0; v < n; v++)
                up[k][v] = up[k - 1][up[k - 1][v]];

        for (int i = 0; i < n; i++) {
            int m = 1 << (s[i] - 'a');
            upd(tin[i], m);
            upd(tout[i] + 1, m);
        }

        vector<bool> ans;
        for (auto& q : queries) {
            istringstream iss(q);
            string type;
            iss >> type;
            if (type == "update") {
                int u;
                char c;
                iss >> u >> c;
                int d = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                if (d) {
                    upd(tin[u], d);
                    upd(tout[u] + 1, d);
                }
                s[u] = c;
            } else {
                int u, v;
                iss >> u >> v;
                int l = lca(u, v);
                int mask = qry(tin[u]) ^ qry(tin[v]) ^ (1 << (s[l] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};