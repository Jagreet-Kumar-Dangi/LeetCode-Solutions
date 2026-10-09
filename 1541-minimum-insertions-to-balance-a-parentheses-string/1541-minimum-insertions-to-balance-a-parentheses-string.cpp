class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0, ins = 0;
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                open++;
                i++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;
                } else {
                    ins++;
                    i++;
                }
                if (open > 0) {
                    open--;
                } else {
                    ins++;
                }
            }
        }
        return ins + open * 2;
    }
};