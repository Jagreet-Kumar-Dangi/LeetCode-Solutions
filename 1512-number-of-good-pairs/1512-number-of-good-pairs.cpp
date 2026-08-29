class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       unordered_map<int,int> mpp;
       int cnt=0;
       for(int num:nums){
        cnt +=mpp[num];
        mpp[num]++;
       }
       return cnt;
       
    }
};