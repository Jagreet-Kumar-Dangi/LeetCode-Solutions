class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return intervals[a][1] < intervals[b][1];
        });

        vector<long long> rArr(n);
        for (int i = 0; i < n; i++) rArr[i] = intervals[order[i]][1];

        struct State {
            long long score;
            vector<int> idx;
        };

        auto better = [](const State& a, const State& b) -> bool {
            if (a.score != b.score) return a.score > b.score;
            return a.idx < b.idx;
        };

        vector<vector<State>> dp(n + 1, vector<State>(5));
        for (int j = 0; j <= 4; j++) dp[0][j] = {0, {}};

        for (int t = 1; t <= n; t++) {
            dp[t][0] = {0, {}};
            int oi = order[t - 1];
            long long l = intervals[oi][0], w = intervals[oi][2];
            int p = lower_bound(rArr.begin(), rArr.end(), l) - rArr.begin();

            for (int j = 1; j <= 4; j++) {
                State cand = dp[t - 1][j];
                State withCur = dp[p][j - 1];
                withCur.score += w;
                auto pos = upper_bound(withCur.idx.begin(), withCur.idx.end(), oi);
                withCur.idx.insert(pos, oi);

                dp[t][j] = better(withCur, cand) ? withCur : cand;
            }
        }

        return dp[n][4].idx;
    }
};