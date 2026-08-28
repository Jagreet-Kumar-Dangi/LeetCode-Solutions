class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int sum=0;
        unordered_map<char,int> mps;
        unordered_map<char,int> mpt;
        for(int i=0;i<s.size();i++){
            mps[s[i]]=i;
        }
        for(int i=0;i<s.size();i++){
            mpt[t[i]]=i;
        }
        for(int i=0;i<s.size();i++){
            sum += abs(mps[s[i]] - mpt[s[i]]);

        }
        return sum;
    }
};