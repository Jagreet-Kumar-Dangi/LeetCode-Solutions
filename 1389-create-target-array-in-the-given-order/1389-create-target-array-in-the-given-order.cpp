class Solution {
public:
    void inserting(vector<int> & arr,int ind,int k){
        int n=arr.size();
        if(arr[ind] !=-1){
            for(int i=n-1;i>ind;i--){
                arr[i]=arr[i-1];
            }
        }
        arr[ind]=k;
    }
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            inserting(ans,index[i],nums[i]);
        }
        return ans;
    }
};