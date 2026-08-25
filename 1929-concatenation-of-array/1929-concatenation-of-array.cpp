class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
    
        nums.insert(nums.end(), nums.begin(), nums.end());
        return(nums);
    }
};