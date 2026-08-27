class Solution {
public:
    int digit(int n){
        int s=0;
        while(n>0){
            int m=n%10;
            s +=m;
            n /=10;
        }
        return s;
    }
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            nums[i]=digit(nums[i]);
            mini=min(mini,nums[i]);
        }
        return mini;
    }
};