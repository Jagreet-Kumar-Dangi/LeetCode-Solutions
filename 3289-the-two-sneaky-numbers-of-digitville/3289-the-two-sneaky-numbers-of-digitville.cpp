class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> hash(n+2,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<n+2;i++){
            if(hash[i]>1)
                ans.push_back(i);
        }
        return ans;
    }
};