class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum < 1 || sum > 9 * num) {
            return "";
        }

        string ans = "";

        while(sum >= 9 && ans.size() < num) {
            ans += '9';
            sum -= 9;
        }

        if(sum > 0 && ans.size() < num) {
            ans += to_string(sum);
        }

        while(ans.size() < num) {
            ans += '0';
        }

        return ans;
    }
};