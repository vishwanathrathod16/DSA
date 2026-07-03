class Solution {
public:

    int kadaneMax(vector<int>& nums)
    {
        int curr = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            curr = max(nums[i], curr + nums[i]);
            ans = max(ans, curr);
        }

        return ans;
    }

    int kadaneMin(vector<int>& nums)
    {
        int curr = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            curr = min(nums[i], curr + nums[i]);
            ans = min(ans, curr);
        }

        return ans;
    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;

        for(int x : nums)
            total += x;

        int maxSum = kadaneMax(nums);

        if(maxSum < 0)
            return maxSum;

        int minSum = kadaneMin(nums);

        return max(maxSum, total - minSum);
    }
};