class Solution {
public:
    bool poss(vector<int>& arr,int m,int k,int day){
        int cnt=0,bouq=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day)
                cnt++;
            else{
                bouq +=cnt/k;
                cnt=0;
            }
        }
        bouq +=cnt/k;
        if(bouq>=m)  return true;
        else    return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int ans=-1;
        for(int x:bloomDay){
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
        int low=mini,high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool res=poss(bloomDay,m,k,mid);
            if(res){
                ans=mid;
                high=mid-1;
            }
            else{
                low =mid+1;
            }
        }
        return ans;

    }
};