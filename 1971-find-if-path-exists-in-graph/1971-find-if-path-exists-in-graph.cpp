class Solution {
public:
    bool dfs(int src,map<int,vector<int>> &mpp,vector<bool> &vis,int dis){
        if(src==dis){
            return true;
        }
        vis[src]=true;
        vector<int> child=mpp[src];
        for(int i=0;i<child.size();i++){
            if(!vis[child[i]]){
                if(dfs(child[i],mpp,vis,dis)==true)
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        map<int,vector<int>> mpp;
        vector<bool> vis(n,false);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            mpp[u].push_back(v);
            mpp[v].push_back(u);
            
        } 
        return dfs(source,mpp,vis,destination);
    }
};