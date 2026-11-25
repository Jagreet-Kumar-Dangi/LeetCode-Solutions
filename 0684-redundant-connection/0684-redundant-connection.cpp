
class Solution {
public:

    bool dfs(int src, int dest, vector<int>& vis,
             vector<list<int>>& l) {

        if(src == dest)
            return true;

        vis[src] = true;

        for(int neigh : l[src]) {
            if(!vis[neigh]) {
                if(dfs(neigh, dest, vis, l))
                    return true;
            }
        }

        return false;
    }

    void addedges(vector<list<int>>& l, int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    vector<int> findRedundantConnection(
        vector<vector<int>>& edges) {

        vector<list<int>> l(edges.size() + 1);

        for(int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            vector<int> vis(edges.size() + 1, 0);

            if(dfs(u, v, vis, l)) {
                return {u, v};
            }

            addedges(l, u, v);
        }

        return {};
    }
};
