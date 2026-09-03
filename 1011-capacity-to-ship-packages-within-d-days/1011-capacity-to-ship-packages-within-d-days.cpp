class Solution {
public:
    bool capacity(vector<int> &arr,int d,int m){
        int cnt=1;
        int sum=0;
        for(int x:arr){
            if (sum + x > m) {
                cnt++;
                sum = x;
            }
            else {
                sum += x;
            }
        }
        return cnt<=d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mini=*max_element(weights.begin(),weights.end());
        int maxi=0;
        for(int x:weights){
            maxi +=x;
        }
        int ans=maxi;
        while(mini<=maxi){
            int mid=mini+(maxi-mini)/2;
            bool res=capacity(weights,days,mid);
            if(res){
                ans=min(ans,mid);
                maxi=mid-1;
            }else{
                mini=mid+1;
            }
        }
        return ans;
    }
};