class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
         int countOdd = 0, countEven = 0;
        for (int x : nums1) {
            if (x % 2 == 0) countEven++;
            else countOdd++;
        }
        bool evenFeasible = (countOdd != 1);
        bool oddFeasible = (countEven == 0) || (countOdd >= 1);
        return evenFeasible || oddFeasible;
    }
};