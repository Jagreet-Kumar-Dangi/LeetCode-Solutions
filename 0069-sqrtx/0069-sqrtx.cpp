class Solution {
public:
    int mySqrt(int x) {
    
        int low=0,high=x/2,ans=0;
        while(low<=high){
            if(x==0)
                return 0;
            if(x==1 || x==2 ||x==3)
                return 1;

            int mid=low+(high-low)/2;
            if(mid==0)
                return x;
            if(mid<=x/mid){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};