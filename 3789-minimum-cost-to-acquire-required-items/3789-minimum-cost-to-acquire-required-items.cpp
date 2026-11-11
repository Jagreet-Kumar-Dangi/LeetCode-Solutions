class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        auto f = [&](long long b) {
            return b * costBoth
                 + max(0LL, (long long)need1 - b) * cost1
                 + max(0LL, (long long)need2 - b) * cost2;
        };
        long long lo = min(need1, need2), hi = max(need1, need2);
        return min({f(0), f(lo), f(hi)});
    }
};