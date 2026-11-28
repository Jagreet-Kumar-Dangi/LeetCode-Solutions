class Solution {
public:
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=true;
        int initial=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i-1>=0 && !vis[i-1][j]&& image[i-1][j]==initial){
                q.push({i-1,j});
                vis[i-1][j]=true;
                image[i-1][j]=color;
            }
            if(i+1<n && !vis[i+1][j]&& image[i+1][j]==initial){
                q.push({i+1,j});
                vis[i+1][j]=true;
                image[i+1][j]=color;
            }
            if(j-1>=0 && !vis[i][j-1]&& image[i][j-1]==initial){
                q.push({i,j-1});
                vis[i][j-1]=true;
                image[i][j-1]=color;
            }
            if(j+1<m && !vis[i][j+1]&& image[i][j+1]==initial){
                q.push({i,j+1});
                vis[i][j+1]=true;
                image[i][j+1]=color;
            }
        }
        return image;
    }
};