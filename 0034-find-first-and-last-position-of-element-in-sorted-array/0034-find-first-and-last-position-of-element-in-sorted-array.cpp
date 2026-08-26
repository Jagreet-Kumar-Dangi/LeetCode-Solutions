class Solution {
public:
    int lowerBound(vector<int> &arr,int k){
        int low=0,high=arr.size()-1,ans=arr.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=k){
                ans=mid;
                high =mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    int upperBound(vector<int> &arr,int k){
        int low=0,high=arr.size()-1,ans=arr.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>k){
                ans=mid;
                high =mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lowerBound(nums,target);
        if(lb==nums.size() || nums[lb] !=target)    return {-1,-1};
        else    return {lb,upperBound(nums,target)-1} ;
    }
};