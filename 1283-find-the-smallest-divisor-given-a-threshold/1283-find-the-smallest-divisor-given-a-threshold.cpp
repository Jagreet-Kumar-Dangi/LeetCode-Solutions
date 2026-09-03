class Solution {
public:
    bool poss(vector<int>& arr,int t,int m){
        int sum=0;
        for(int x:arr){
            sum +=(x+m-1)/m;
        }
        if(sum<=t)  return true;
        else    return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi= *max_element(nums.begin(),nums.end());
        int mini= 1;
        int ans=maxi;
        while(mini<=maxi){
            int mid=mini+(maxi-mini)/2;
            bool res=poss(nums,threshold,mid);
            if(res){
                ans=min(mid,ans);
                maxi=mid-1;
            }else{
                mini=mid+1;
            }
        }
        return ans;

    }
};