class Solution {
public:
    long long countCommas(long long n) {

        long long x = 0;
        long long y = 0;
        long long z = 0;
        long long w = 0;

        if(n<1000) return 0;

        else if(n >= 1000 && n < 1000000){
            long long x = n-1000+1;
            return x;
        }
        else if(n >= 1000000 && n < 1000000000){
            long long  y = 999999 - 1000 +1  + (n - 1000000 + 1)*2;
            return y;
        }
        else if(n >= 1000000000 && n < 1000000000000){
            long long z = (999999 - 1000 +1) +(999999999 - 1000000+ 1)*2+ (n - 1000000000 +1)*3;
            return z;
        }
        else if(n >= 1000000000000 && n < 1000000000000000){
            long long w = (999999 - 1000 +1) +(999999999 - 1000000+ 1)*2+ (999999999999 - 1000000000+1)*3 + (n- 1000000000000 + 1)*4;
            return w;
        }
        else {
            return (999999 - 1000 +1) +(999999999 - 1000000+ 1)*2+ (999999999999 - 1000000000 +1)*3 + (999999999999999- 1000000000000 + 1)*4+5;
        }    
    }
};