class Solution {
public:
    int reverseDegree(string s) {
        int p=0;
        for(int i=0;i<s.size();i++){
            p += (26-(s[i]-'a'))*(i+1);
        }
        return p;
    }
};