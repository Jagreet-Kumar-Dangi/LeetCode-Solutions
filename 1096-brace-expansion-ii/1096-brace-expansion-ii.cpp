class Solution {
public:
    int pos;
    string expr;

    set<string> parseExpr() {
        set<string> result;
        set<string> current = parseTerm();
        result = current;
        while (pos < (int)expr.size() && expr[pos] == ',') {
            pos++;
            set<string> next = parseTerm();
            for (auto& s : next) result.insert(s);
        }
        return result;
    }

    set<string> parseTerm() {
        vector<set<string>> factors;
        while (pos < (int)expr.size() && expr[pos] != ',' && expr[pos] != '}') {
            factors.push_back(parseFactor());
        }
        set<string> result;
        result.insert("");
        for (auto& f : factors) {
            set<string> newResult;
            for (auto& a : result) {
                for (auto& b : f) {
                    newResult.insert(a + b);
                }
            }
            result = newResult;
        }
        return result;
    }

    set<string> parseFactor() {
        if (expr[pos] == '{') {
            pos++;
            set<string> res = parseExpr();
            pos++;
            return res;
        } else {
            string s(1, expr[pos]);
            pos++;
            return {s};
        }
    }
    vector<string> braceExpansionII(string expression) {
        expr = expression;
        pos = 0;
        set<string> result = parseExpr();
        return vector<string>(result.begin(), result.end());
    }
};