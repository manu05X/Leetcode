class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // Count the total number of ones in the input vector
        int oneCount = 0;
        for (int value : nums) {
            oneCount += value;
        }

        int n = nums.size();
        // Initialize an extended sum vector that is twice as long as the input
        // This is used to simulate a circular array
        vector<int> prefixSum((n << 1) + 1, 0);
        for (int i = 0; i < (n << 1); ++i) {
            // Populate the prefix sum array by adding the current element
            // Note: Use modulus to simulate the circular array
            prefixSum[i + 1] = prefixSum[i] + nums[i % n];
        }

        int maxOnes = 0;
        // Slide a window of length equal to the number of ones (oneCount)
        // over the prefix sum array to find the maximum number of ones in any
        // subarray of the same length
        for (int i = 0; i < (n << 1); ++i) {
            // Calculate the end of the window
            int windowEnd = i + oneCount - 1;
            // Ensure that we do not go past the end of the sum array
            if (windowEnd < (n << 1)) {
                int windowSum = prefixSum[windowEnd + 1] - prefixSum[i];
                maxOnes = max(maxOnes, windowSum);
            }
        }

        // The minimum number of swaps needed is the difference between
        // the number of ones in the array and the maximum number of ones
        // found in any window of size equal to the number of ones.
        // This tells us how many zeros we need to swap out of the window.
        return oneCount - maxOnes;
    }
};