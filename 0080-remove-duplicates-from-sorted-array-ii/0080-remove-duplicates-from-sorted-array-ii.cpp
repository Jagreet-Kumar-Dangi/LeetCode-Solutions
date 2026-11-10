class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        int cnt = 1;

        if (nums.size() == 0) 
            return 0;

        ans.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] == nums[i-1]) {
                cnt++;
            }
            else {
                cnt = 1;
            }

            if (cnt <= 2) {
                ans.push_back(nums[i]);
            }
        }

        nums = ans;
        return ans.size();
    }
};