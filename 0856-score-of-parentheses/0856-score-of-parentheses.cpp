class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        stk.push(0);
        for (char c : s) {
            if (c == '(') {
                stk.push(0);
            } else {
                int v = stk.top(); stk.pop();
                int score = (v == 0) ? 1 : 2 * v;
                stk.top() += score;
            }
        }
        return stk.top();
    }
};