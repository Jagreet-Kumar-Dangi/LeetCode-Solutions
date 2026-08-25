class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int sign=1;
        for(int i=0;i<n;i++){
            // if(i%2==0)
            //     sum +=nums[i];
            // else
            //     sum -=nums[i];
            sum +=sign*nums[i];
            sign = -sign;
        }
        return sum;
    }
};