class Solution {
public:
    string truncateSentence(string s, int k) {
        string sen="";
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')
                cnt++;
            if(cnt==k)
                break;
            sen +=s[i];
        }
        return sen;
    }
};