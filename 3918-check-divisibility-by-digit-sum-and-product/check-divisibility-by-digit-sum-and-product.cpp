class Solution {
public:
    bool checkDivisibility(int n) {
        int curr_n = n;
        int sum = 0;
        int product = 1;
        while(n>0){
            sum += n%10;
            product *= n%10;
            n = n/10;


        }
        int ans = sum+product;
        if(curr_n%ans==0){
            return true;
        }
        else{
            return false;
        }

        
    }
};