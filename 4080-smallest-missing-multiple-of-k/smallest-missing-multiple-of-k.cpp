class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sMelmt = 1*k;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == sMelmt){
                sMelmt += k;
            }
        }
        return sMelmt;
        
    }
};