class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt=0;
        int r=0,l=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R'){
                r++;
                if(r==l && r!=0)
                    cnt++;
            }else{
                l++;
                if(r==l && l !=0)
                    cnt++;
            }  
        }
        return cnt;      
    }
};