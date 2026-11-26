class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        bool alice = true;
        while (take > 0 && n >= take) {
            n -= take;
            take--;
            alice = !alice;
        }
        return !alice;
    }
};