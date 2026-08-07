class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            bool found = false;

            for(int x : ans)
                if(x == nums[i])
                    found = true;

            if(found)
                continue;

            int cnt = 0;

            for(int j = 0; j < n; j++) {

                if(nums[j] == nums[i])
                    cnt++;
            }

            if(cnt > n / 3)
                ans.push_back(nums[i]);
        }

        return ans;
    }
};