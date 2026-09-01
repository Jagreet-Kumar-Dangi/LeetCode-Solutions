class Solution {
public:
    int subtractProductAndSum(int n) {
        int p=1,s=0;
        while(n>0){
            int mod=n%10;
            p *=mod;
            s +=mod;
            n /=10;
        }
        return p-s;
    }
};