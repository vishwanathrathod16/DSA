class Solution {
public:
    vector<vector<int>> dp;
    unordered_map<int, int> pos;

    bool solve(int idx, int jump, vector<int>& stones) {

        int n = stones.size();

        if (idx == n - 1)
            return true;

        if (dp[idx][jump] != -1)
            return dp[idx][jump];

        for (int nj = jump - 1; nj <= jump + 1; nj++) {

            if (nj <= 0)
                continue;

            int nextStone = stones[idx] + nj;

            if (pos.count(nextStone)) {

                if (solve(pos[nextStone], nj, stones))
                    return dp[idx][jump] = true;
            }
        }

        return dp[idx][jump] = false;
    }

    bool canCross(vector<int>& stones) {

        int n = stones.size();

        if (stones[1] != 1)
            return false;

        dp.assign(n, vector<int>(n + 1, -1));

        for (int i = 0; i < n; i++)
            pos[stones[i]] = i;

        return solve(1, 1, stones);
    }
};