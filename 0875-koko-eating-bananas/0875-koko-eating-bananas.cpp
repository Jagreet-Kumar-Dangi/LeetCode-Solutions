class Solution {
public:
    long long hrs(vector<int> &arr,int time){
        long long int thrs=0;
        for(int i=0;i<arr.size();i++){
            thrs +=(arr[i]+time-1ll)/time;
        }
        return thrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        
        int maxi=piles[0];
        for(int i=1;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int high=maxi;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long  reqTime=hrs(piles,mid);
            if(reqTime<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};