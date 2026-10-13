class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>small;
        vector<int>big;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]=abs(nums[i]);
            }
        }
        sort(nums.begin(),nums.end());
        long long addsum = 0;
        long long subsum = 0;
        for(int i=0;i<n/2;i++){
            small.push_back(nums[i]);
            subsum += nums[i]*nums[i];
        }
        for(int i=n/2;i<n;i++){
            big.push_back(nums[i]);
            addsum += nums[i]*nums[i];
        }
        return addsum - subsum;

        
    }
};