class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int n = nums1.size();
        int even = 0;
        int odd = 0;
        vector<int> nums2;
        if(nums1.size()==1){
            return true;
        }

        for(int i = 0; i < n; i++) {
            if(nums1[i] % 2 == 0)
                even++;
            else
                odd++;
        }

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(even == 1 || odd == 1) {

                    if(nums1[i] % 2 != 0) {
                        nums2.push_back(nums1[i]);
                        break;  // CORRECTION
                    }
                    else {
                        if(nums1[i] % 2 == 0 && i != j) {

                            if((nums1[i] - nums1[j]) % 2 != 0) {
                                nums2.push_back(nums1[i] - nums1[j]);
                                break;
                            }
                        }
                    }
                }
                else {

                    if(nums1[i] % 2 == 0) {
                        nums2.push_back(nums1[i]);
                        break;  // CORRECTION
                    }
                    else if(nums1[i] % 2 != 0 && i != j) {

                        if((nums1[i] - nums1[j]) % 2 == 0) {
                            nums2.push_back(nums1[i] - nums1[j]);
                            break;
                        }
                    }
                }
            }
        }

        if(nums1.size() == nums2.size()) {
            return true;
        }

        return false;
    }
};