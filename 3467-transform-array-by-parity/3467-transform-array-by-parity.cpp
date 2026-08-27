class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            (nums[i]%2==0)?nums[i]=0:nums[i]=1;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};