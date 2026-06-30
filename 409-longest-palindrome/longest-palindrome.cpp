class Solution {
public:
    int longestPalindrome(string s) {

        vector<int> freq(128, 0);

        for(char ch : s)
            freq[ch]++;

        int ans = 0;
        bool hasOdd = false;

        for(int x : freq)
        {
            ans += (x / 2) * 2;

            if(x % 2 == 1)
                hasOdd = true;
        }

        if(hasOdd)
            ans++;

        return ans;
    }
};