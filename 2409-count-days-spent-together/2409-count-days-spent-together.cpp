class Solution {
public:
    int toDay(const string& d) {
        static int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int m = stoi(d.substr(0, 2));
        int dd = stoi(d.substr(3, 2));
        int total = 0;
        for (int i = 0; i < m - 1; i++) total += days[i];
        return total + dd;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(toDay(arriveAlice), toDay(arriveBob));
        int end = min(toDay(leaveAlice), toDay(leaveBob));
        return max(0, end - start + 1);
    }
};