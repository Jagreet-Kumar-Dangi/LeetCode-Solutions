class Solution {
public:
    int binary(vector<int> &arr,int low,int high,int tar){
        if(low>high)    return -1;
        int mid=(low+high)/2;
        if(arr[mid]==tar)   return mid;
        else if(arr[mid]<tar)   return binary(arr,mid+1,high,tar);
        else    return binary(arr,low,mid-1,tar);
    }
    int search(vector<int>& nums, int target) {
        return binary(nums,0,nums.size()-1,target);
    
        
    }
};