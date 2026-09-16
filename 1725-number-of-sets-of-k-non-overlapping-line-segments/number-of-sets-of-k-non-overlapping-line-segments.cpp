class Solution {
public:
    int numberOfSets(int n, int k) {
        
        long long ans = 1;
        int MOD = 1000000007;

        for(int i = 1; i <= 2 * k; i++) {
            ans = ans * (n + k - i) % MOD;
            ans = ans * modInverse(i, MOD) % MOD;
        }

        return ans;
    }

    long long modInverse(long long a, int MOD) {
        long long result = 1;
        long long power = MOD - 2;

        while(power > 0) {
            if(power % 2 == 1)
                result = result * a % MOD;

            a = a * a % MOD;
            power = power / 2;
        }

        return result;
    }
};