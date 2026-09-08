class Solution {
public:
    int ind(vector<vector<int>> & mat,int n,int col){
        int maxi=-1;
        int in=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                in=i;
            }
        }
        return in;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0,h=m-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int maxInd=ind(mat,n,mid);
            int left=mid-1>=0?mat[maxInd][mid-1]:-1;
            int right=mid+1<m?mat[maxInd][mid+1]:-1;
            if(mat[maxInd][mid]>left && mat[maxInd][mid]>right)
                return {maxInd,mid};
            else if(mat[maxInd][mid]<left)  h=mid-1;
            else    l=mid+1;
        }
        return {-1,-1};
    }
};