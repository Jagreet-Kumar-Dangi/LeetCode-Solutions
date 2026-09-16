class Solution {
public:
     const int MOD = 1e9 + 7;

    long long power(long long a, long long b, long long mod) {
        long long res = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    int numberOfSets(int n, int k) {
        int maxN = n + k;
        vector<long long> fact(maxN + 1), invFact(maxN + 1);
        fact[0] = 1;
        for (int i = 1; i <= maxN; i++) fact[i] = fact[i-1] * i % MOD;
        invFact[maxN] = power(fact[maxN], MOD - 2, MOD);
        for (int i = maxN - 1; i >= 0; i--) invFact[i] = invFact[i+1] * (i+1) % MOD;

        int N = n + k - 1;
        int R = 2 * k;
        if (R > N) return 0;
        long long res = fact[N] * invFact[R] % MOD * invFact[N - R] % MOD;
        return (int)res;
    }
};