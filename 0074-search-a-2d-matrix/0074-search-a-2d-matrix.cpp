class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,h=matrix.size()-1;

        while(l<=h){
            int mid=l+(h-l)/2;
            if(matrix[mid][0]<=target){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        if(h<0)
            return false;
        int low=0,high=matrix[0].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[h][mid]==target)  return true;
            else if(matrix[h][mid]>target)  high=mid-1;
            else    low=mid+1;
        }
        return false;
    }
};