class Solution {
public:
    int maxFreqSum(string s) {
        int hash[150]={0},hash1[150]={0};
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                hash[s[i]]++;
            else
                hash1[s[i]]++;
        }
        int lar1=0,lar2=0;
        for(int x:hash){
            if(x>lar1)
                lar1=x;
        }
        for(int x:hash1){
            if(x>lar2)
                lar2=x;
        }
        return lar1+lar2;

    }
};