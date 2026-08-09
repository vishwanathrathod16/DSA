class Solution {
public:
    int n;
    vector<int> suffix;
    int memo[101][101];

    int solve(int i, int M, vector<int>& piles) {

        if (i >= n)
            return 0;

        if (2 * M >= n - i)
            return suffix[i];

        if (memo[i][M] != -1)
            return memo[i][M];

        int ans = 0;

        for (int X = 1; X <= 2 * M; X++) {

            ans = max(ans,
                      suffix[i] - solve(i + X, max(M, X), piles));
        }

        return memo[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        suffix.resize(n);

        suffix[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = piles[i] + suffix[i + 1];

        memset(memo, -1, sizeof(memo));

        return solve(0, 1, piles);
    }
};