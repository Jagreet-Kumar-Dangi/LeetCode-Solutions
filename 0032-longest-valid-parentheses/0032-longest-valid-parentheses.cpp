class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        stk.push(-1);
        int best = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    best = max(best, i - stk.top());
                }
            }
        }
        return best;
    }
};