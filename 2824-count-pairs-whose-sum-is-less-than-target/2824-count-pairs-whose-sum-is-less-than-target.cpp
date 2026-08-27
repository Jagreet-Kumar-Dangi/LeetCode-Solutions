class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]<target){
                cnt +=j-i;
                i++;
            }else{
                j--;
            }
        }
        return cnt;
    }
};