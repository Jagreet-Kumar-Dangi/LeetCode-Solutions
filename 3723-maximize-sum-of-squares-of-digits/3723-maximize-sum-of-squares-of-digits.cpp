class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";
        string res;
        res.reserve(num);
        int remaining = sum;
        for (int i = 0; i < num; i++) {
            int d = min(9, remaining);
            res += char('0' + d);
            remaining -= d;
        }
        return res;
    }
};