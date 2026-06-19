class Solution {
public:
    
    void solve(int idx, vector<int>& candidates, int target,
               vector<int>& ds, vector<vector<int>>& ans) {
        
        if (idx == candidates.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (candidates[idx] <= target) {
            ds.push_back(candidates[idx]);

            solve(idx, candidates, target - candidates[idx], ds, ans);

            ds.pop_back();
        }

        solve(idx + 1, candidates, target, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, candidates, target, ds, ans);

        return ans;
    }
};