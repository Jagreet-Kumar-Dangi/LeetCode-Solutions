class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
         int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int,int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) continue;
            int lo = first[c], hi = last[c];
            bool changed = true;
            while (changed) {
                changed = false;
                for (int i = lo; i <= hi; i++) {
                    int ch = s[i] - 'a';
                    if (first[ch] < lo) { lo = first[ch]; changed = true; }
                    if (last[ch] > hi) { hi = last[ch]; changed = true; }
                }
            }
            if (lo == first[c]) {
                intervals.push_back({lo, hi});
            }
        }

        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        });

        vector<string> res;
        int lastEnd = -1;
        for (auto& [lo, hi] : intervals) {
            if (lo > lastEnd) {
                res.push_back(s.substr(lo, hi - lo + 1));
                lastEnd = hi;
            }
        }
        return res;
    }
};