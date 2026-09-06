class Solution {
public:

    int dp[1001][1001];

    int fun(int i, int j, string& s, string& t) {

        // Target completely formed
        if(j == t.size())
            return 1;

        // S completely finished
        if(i == s.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        // Characters match
        if(s[i] == t[j]) {

            int take = fun(i + 1, j + 1, s, t);

            int notTake = fun(i + 1, j, s, t);

            ans = take + notTake;
        }

        // Characters don't match
        else {

            ans = fun(i + 1, j, s, t);
        }

        return dp[i][j] = ans;
    }


    int numDistinct(string s, string t) {

        memset(dp, -1, sizeof(dp));

        return fun(0, 0, s, t);
    }
};