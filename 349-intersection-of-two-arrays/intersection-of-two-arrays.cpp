class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> st(nums1.begin(), nums1.end());
        unordered_set<int> ansSet;

        for (int x : nums2) {
            if (st.find(x) != st.end())
                ansSet.insert(x);
        }

        vector<int> ans;

        for (int x : ansSet)
            ans.push_back(x);

        return ans;
    }
};