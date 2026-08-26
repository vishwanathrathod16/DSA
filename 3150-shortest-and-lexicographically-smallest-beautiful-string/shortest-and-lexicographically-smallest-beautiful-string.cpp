class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int minLen = INT_MAX;

        for(int i = 0; i < n; i++) {

            if(s[i] == '1') {

                int one = 0;

                for(int j = i; j < n; j++) {

                    if(s[j] == '1') {
                        one++;
                    }

                    // We found a substring having exactly k ones
                    if(one == k) {

                        int len = j - i + 1;

                        string temp = s.substr(i, len);

                        // First check smaller length
                        if(len < minLen) {
                            minLen = len;
                            ans = temp;
                        }

                        // If same length, take lexicographically smaller
                        else if(len == minLen && temp < ans) {
                            ans = temp;
                        }

                        break;
                    }
                }
            }
        }

        return ans;
    }
};