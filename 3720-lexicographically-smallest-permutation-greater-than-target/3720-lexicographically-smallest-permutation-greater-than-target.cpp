class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
         int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int matched = 0;
        while (matched < n && cnt[target[matched] - 'a'] > 0) {
            cnt[target[matched] - 'a']--;
            matched++;
        }

        int start;
        if (matched == n) {
            start = n - 1;
            cnt[target[n - 1] - 'a']++;
        } else {
            start = matched;
        }

        for (int i = start; i >= 0; i--) {
            int tc = target[i] - 'a';
            int found = -1;
            for (int c = tc + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    found = c;
                    break;
                }
            }

            if (found != -1) {
                cnt[found]--;
                string res = target.substr(0, i);
                res += char('a' + found);
                for (int c = 0; c < 26; c++) {
                    res += string(cnt[c], char('a' + c));
                }
                return res;
            }

            if (i - 1 >= 0) {
                cnt[target[i - 1] - 'a']++;
            }
        }

        return "";
    }
};