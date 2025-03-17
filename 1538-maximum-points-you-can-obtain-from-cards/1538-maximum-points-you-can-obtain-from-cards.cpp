class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(); // Total number of cards

        // Calculate the sum of the first 'k' cards (left window)
        int leftSum = 0;
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        // Initialize maxSum with the sum of the first 'k' cards
        int maxSum = leftSum;

        // Use a sliding window approach to consider combinations of left and right cards
        int rightSum = 0; // Sum of cards from the right side
        for (int i = 0; i < k; i++) {
            // Remove the last card from the left window
            leftSum -= cardPoints[k - 1 - i];
            // Add the corresponding card from the right window
            rightSum += cardPoints[n - 1 - i];

            // Update maxSum with the maximum of the current maxSum and the new sum (leftSum + rightSum)
            maxSum = max(maxSum, leftSum + rightSum);
        }

        // Return the maximum score achievable
        return maxSum;
    }
};


//