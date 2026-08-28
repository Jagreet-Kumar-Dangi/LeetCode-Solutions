class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        int oddCount = 0, oddChar = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) { oddCount++; oddChar = i; }
        }
        if (n % 2 == 0 && oddCount != 0) return "";
        if (n % 2 == 1 && oddCount != 1) return "";

        int h = n / 2;
        int half[26];
        for (int i = 0; i < 26; i++) half[i] = cnt[i] / 2;
        bool odd = (n % 2 == 1);
        char midChar = odd ? char('a' + oddChar) : 0;

        string prefix = target.substr(0, h);
        int pc[26] = {0};
        for (char c : prefix) pc[c - 'a']++;
        bool prefixMatches = true;
        for (int i = 0; i < 26; i++) if (pc[i] != half[i]) { prefixMatches = false; break; }

        if (prefixMatches) {
            if (odd) {
                if (midChar > target[h]) {
                    string rev = prefix;
                    reverse(rev.begin(), rev.end());
                    return prefix + string(1, midChar) + rev;
                } else if (midChar == target[h]) {
                    string suffix = target.substr(h + 1);
                    string rev = prefix;
                    reverse(rev.begin(), rev.end());
                    if (rev > suffix) return prefix + string(1, midChar) + rev;
                }
            } else {
                string suffix = target.substr(h);
                string rev = prefix;
                reverse(rev.begin(), rev.end());
                if (rev > suffix) return prefix + rev;
            }
        }

        int counts[26];
        for (int i = 0; i < 26; i++) counts[i] = half[i];
        int devPos = -1, devChar = -1;
        int devSnapshot[26] = {0};

        for (int i = 0; i < h; i++) {
            int targetC = prefix[i] - 'a';
            for (int c = targetC + 1; c < 26; c++) {
                if (counts[c] > 0) {
                    devPos = i;
                    devChar = c;
                    for (int k = 0; k < 26; k++) devSnapshot[k] = counts[k];
                    break;
                }
            }
            if (counts[targetC] > 0) {
                counts[targetC]--;
            } else {
                break;
            }
        }

        if (devPos == -1) return "";

        string A = prefix.substr(0, devPos);
        A += char('a' + devChar);
        int fillCounts[26];
        for (int k = 0; k < 26; k++) fillCounts[k] = devSnapshot[k];
        fillCounts[devChar]--;
        for (int c = 0; c < 26; c++) {
            for (int k = 0; k < fillCounts[c]; k++) A += char('a' + c);
        }

        string rev = A;
        reverse(rev.begin(), rev.end());
        string S = A;
        if (odd) S += midChar;
        S += rev;
        return S;
    }
};