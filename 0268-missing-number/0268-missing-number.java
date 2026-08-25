class Solution {
    public int missingNumber(int[] nums) {
        int n=nums.length;
        int x1=0;
        int x2=0;
        for(int i=0;i<n;i++){
            x1 ^=nums[i];
            x2 ^=i;
        }
        x2 ^=n;
        return x1^x2;
    }
}