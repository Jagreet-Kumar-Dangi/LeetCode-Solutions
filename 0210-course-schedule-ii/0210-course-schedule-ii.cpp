class Solution {
public:
    bool dfs(int curr,vector<vector<int>>& pre,vector<bool>& vis,vector<bool>& rec,stack<int>& s){
        vis[curr]=true;
        rec[curr]=true;
        for(int x:pre[curr]){
            if(!vis[x]){
                if(dfs(x,pre,vis,rec,s)){
                    return true;
                }
            }else if(rec[x])
                return true;
        }
        rec[curr]=false;
        s.push(curr);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<bool> vis(n,false);
        vector<bool> rec(n,false);
        stack<int> s;
        vector<int> ans;
        vector<vector<int>> adj(n);
        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i])
                if(dfs(i,adj,vis,rec,s)){
                    return {};
                }
        }
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};