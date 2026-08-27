class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int x=0,j=n;
        for(int i=0;i<2*n;i++){
            if(i%2==0){
                ans.push_back(nums[x]);
                x++;
            }else{
                ans.push_back(nums[j]);
                j++;
            }
        }
        return ans;
    }
};