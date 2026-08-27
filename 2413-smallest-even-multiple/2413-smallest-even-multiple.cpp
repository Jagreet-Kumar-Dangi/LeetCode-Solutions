class Solution {
public:
    int smallestEvenMultiple(int n) {
        for(int i=1;i<=150;i++){
            if(i%2==0 && i%n==0)
                return i;
        }
        return n*2;
    }
};