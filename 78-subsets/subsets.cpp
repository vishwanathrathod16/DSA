class Solution {
public:

    vector<vector<int>> ans;

    void solve(int ind, vector<int>& nums, vector<int>& ds)
    {
        if(ind == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[ind]);
        solve(ind + 1, nums, ds);

        ds.pop_back();
        solve(ind + 1, nums, ds);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> ds;

        solve(0, nums, ds);

        return ans;
    }
};