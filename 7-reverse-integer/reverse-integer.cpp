class Solution {
public:
    int reverse(int x) {
        string s = to_string(abs((long long)x));

        std::reverse(s.begin(), s.end());

        long long ans = stoll(s);

        if (x < 0) ans = -ans;

        if (ans < INT_MIN || ans > INT_MAX)
            return 0;

        return (int)ans;
    }
};