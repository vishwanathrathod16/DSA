class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    bool check(long long x, vector<int>& coins, int k) {

        long long cnt = 0;
        int n = coins.size();

        for (int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    L = lcm(L, coins[i]);

                    if (L > x)
                        break;
                }
            }

            int bits = __builtin_popcount(mask);

            if (bits % 2 == 1)
                cnt += x / L;
            else
                cnt -= x / L;
        }

        return cnt >= k;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 1LL * k * (*min_element(coins.begin(), coins.end()));

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (check(mid, coins, k))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};