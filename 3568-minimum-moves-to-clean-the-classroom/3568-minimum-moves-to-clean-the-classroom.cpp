class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1;
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        int L = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') { sr = i; sc = j; }
                else if (classroom[i][j] == 'L') { litterIdx[i][j] = L++; }
            }
        }
        int target = (1 << L) - 1;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int>(1 << L, -1)));

        struct State { int r, c, e, mask, moves; };
        queue<State> q;

        int startMask = 0;
        best[sr][sc][0] = energy;
        q.push({sr, sc, energy, 0, 0});

        while (!q.empty()) {
            State cur = q.front(); q.pop();
            if (cur.mask == target) return cur.moves;
            if (cur.e == 0) continue;
            for (int d = 0; d < 4; d++) {
                int nr = cur.r + dr[d], nc = cur.c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (classroom[nr][nc] == 'X') continue;
                int ne = cur.e - 1;
                if (classroom[nr][nc] == 'R') ne = energy;
                int nmask = cur.mask;
                if (classroom[nr][nc] == 'L') nmask |= (1 << litterIdx[nr][nc]);
                if (ne > best[nr][nc][nmask]) {
                    best[nr][nc][nmask] = ne;
                    q.push({nr, nc, ne, nmask, cur.moves + 1});
                }
            }
        }
        return -1;
    }
};