class Solution {
public:
    const long long MOD = 1000000007;

    long long modPow(long long base, long long exp) {
        long long ans = 1;

        base %= MOD;

        while (exp > 0) {
            if (exp & 1)
                ans = (ans * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return ans;
    }

    int minNonZeroProduct(int p) {

        long long mx = (1ULL << p) - 1;
        long long second = mx - 1;
        long long cnt = (1ULL << (p - 1)) - 1;

        return (modPow(second, cnt) * (mx % MOD)) % MOD;
    }
};