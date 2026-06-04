class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int leftSum = 0;

        // Take first k cards from left
        for(int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        int maxSum = leftSum;
        int rightSum = 0;
        int rightIndex = n - 1;

        // Replace left cards with right cards one by one
        for(int i = k - 1; i >= 0; i--) {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIndex];
            rightIndex--;

            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};