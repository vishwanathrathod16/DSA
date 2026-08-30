class Solution { 
public: 
    int minimumDeletions(vector<int>& nums) { 

        int n = nums.size(); 
        int deletion = 0; 

        int mini = INT_MAX; 
        int maxi = INT_MIN; 

        int miniidx = -1; 
        int maxiidx = -1; 

        for(int i = 0; i < n; i++) { 

            if(nums[i] < mini) { 
                mini = min(mini, nums[i]); 
                miniidx = i; 
            } 

            if(nums[i] > maxi) { 
                maxi = max(maxi, nums[i]); 
                maxiidx = i; 
            } 
        }  

        int a = max(miniidx, maxiidx) + 1;

        int b = n - min(miniidx, maxiidx);

        int c = min(miniidx, maxiidx) + 1 
                + (n - max(miniidx, maxiidx));

        deletion = min(a, min(b, c));

        return deletion; 
    } 
};