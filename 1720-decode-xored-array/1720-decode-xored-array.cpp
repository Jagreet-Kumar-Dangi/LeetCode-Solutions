class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        int x=first;
        for(int i=0;i<encoded.size();i++){
            x ^=encoded[i];
            ans.push_back(x);
        }
        return ans;
    }
};