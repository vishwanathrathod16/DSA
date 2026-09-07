class Solution {
public:
    int distinctSubseqII(string s) {

        int n = s.size();
        int MOD = 1e9 + 7;

        vector<long long> dp(n + 1, 0);


        vector<int> last(26, -1);

        for(int i = 0; i < n; i++) {

        
            dp[i + 1] = (2 * dp[i] + 1) % MOD;

            
            if(last[s[i] - 'a'] != -1) {

                int prev = last[s[i] - 'a'];

                dp[i + 1] = (dp[i + 1] - dp[prev] - 1 + MOD) % MOD;
            }

            last[s[i] - 'a'] = i;
        }

        return dp[n];
    }
};