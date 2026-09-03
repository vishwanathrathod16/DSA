class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int mn = INT_MAX;

        for(int i = 0; i < nums1.size(); i++) {

            if(nums1[i] % 2 != 0) {
                mn = min(mn, nums1[i]);
            }
        }

        for(int i = 0; i < nums1.size(); i++) {

            if(nums1[i] % 2 == 0 &&
               mn != INT_MAX &&
               nums1[i] < mn) {

                return false;
            }
        }

        return true;
    }
};