class Solution {
public:

    int solve(vector<int>& nums, int k) {

        if(k < 0)
            return 0;

        int left = 0;
        int right = 0;
        int cnt = 0;

        unordered_map<int,int> mpp;

        while(right < nums.size()) {

            mpp[nums[right]]++;

            while(mpp.size() > k) {

                mpp[nums[left]]--;

                if(mpp[nums[left]] == 0)
                    mpp.erase(nums[left]);

                left++;
            }

            cnt += (right - left + 1);

            right++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return solve(nums, k) - solve(nums, k - 1);
    }
};