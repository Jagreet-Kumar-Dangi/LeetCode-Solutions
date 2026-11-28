class Solution {
public:
    bool dfs(int curr,vector<vector<int>>& pre,vector<bool>& vis,vector<bool>& rec){
        vis[curr]=true;
        rec[curr]=true;
        for(int x:pre[curr]){
            if(!vis[x]){
                if(dfs(x,pre,vis,rec))
                    return true;
            }else if(rec[x])
                return true;
        }
        rec[curr]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<bool> vis(n,false);
        vector<bool> rec(n,false);
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
        }
     
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,rec))
                    return false;
            }
        }
        return true;
    }
};