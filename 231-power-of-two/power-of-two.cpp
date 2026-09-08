class Solution {
public:
    bool isPowerOfTwo(int n) {
        string ans = "";

        while(n > 0) {
            ans.push_back((n % 2) + '0');
            n = n / 2;
        }

        reverse(ans.begin(), ans.end());
        
        int sum =0;

        for(int i = 0;i<ans.size();i++){
            sum += ans[i]-'0';
        }
        if(sum == 1) return true;
        return false;

        
    }
};