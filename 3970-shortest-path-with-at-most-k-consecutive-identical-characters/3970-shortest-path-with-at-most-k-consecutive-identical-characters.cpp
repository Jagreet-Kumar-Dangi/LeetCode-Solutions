class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});

        int W = k + 1;
        const int INF = INT_MAX;
        vector<int> dist((size_t)n * W, INF);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[0 * W + 1] = 0;
        pq.push({0, 0 * W + 1});

        while (!pq.empty()) {
            auto [d, state] = pq.top(); pq.pop();
            if (d > dist[state]) continue;
            int u = state / W, run = state % W;
            if (u == n - 1) return d;
            for (auto& [v, w] : adj[u]) {
                int nrun = (labels[v] == labels[u]) ? run + 1 : 1;
                if (nrun > k) continue;
                int ns = v * W + nrun;
                int nd = d + w;
                if (nd < dist[ns]) {
                    dist[ns] = nd;
                    pq.push({nd, ns});
                }
            }
        }
        return -1;
    }
};