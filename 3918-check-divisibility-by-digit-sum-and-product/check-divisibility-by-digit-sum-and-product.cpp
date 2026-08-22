class Solution {
public:
    int productsum(int n){
        int prod = 1;
        while(n){
            int lastdigit = n % 10;
            prod = prod*lastdigit;
            n = n/10;
        }
        return prod;
    }
    int digitsum(int n){
        int sum = 0;
        while(n){
        int lastdigit = n % 10;
            sum += lastdigit;
            n = n/10;
        }
        return sum;
        

    }
    bool checkDivisibility(int n) {
        int x = digitsum(n);
        int y = productsum(n);
        if(n % (x+y) == 0) return true;
        return false;
        
    }
};