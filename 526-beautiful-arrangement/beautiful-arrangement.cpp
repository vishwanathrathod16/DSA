class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int mask) {
        if (mask == (1 << n) - 1)
            return 1;

        if (dp[mask] != -1)
            return dp[mask];

        int pos = __builtin_popcount(mask) + 1;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                int num = i + 1;
                if (num % pos == 0 || pos % num == 0)
                    ans += solve(mask | (1 << i));
            }
        }

        return dp[mask] = ans;
    }

    int countArrangement(int N) {
        n = N;
        dp.assign(1 << n, -1);
        return solve(0);
    }
};