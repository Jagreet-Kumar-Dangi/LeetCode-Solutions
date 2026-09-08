class Solution {
public:
    int countCommas(int n) {
        int cnt = 0;

        if (n >= 1000)
            cnt += n - 999;

        if (n >= 1000000)
            cnt += n - 999999;

        if (n >= 1000000000)
            cnt += n - 999999999;

        return cnt;
    }
};