class Solution {
public:
    int sumCounts(vector<int>& nums) {

        int n = nums.size();
        int distVal = 0;
        set<int>st;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                st.insert(nums[j]);
                int k = st.size();
                distVal += k*k;
            }
            st.clear();
        }
        return distVal;
    }
};