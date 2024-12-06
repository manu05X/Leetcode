class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l; // Get the size of the array and initialize variables

        // Step 1: Find the first decreasing element from the end
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) { // Check if the current element is smaller than the next
                break; // Stop as soon as we find the first decreasing element
            }
        }

        // Step 2: If no such element exists, reverse the array to get the smallest permutation
        if (k < 0) {
            reverse(nums.begin(), nums.end()); // Reverse the array to get the lowest permutation
        } else {
            // Step 3: Find the smallest element larger than nums[k] to its right
            for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) { // Find an element larger than nums[k]
                    break;
                }
            }
            // Step 4: Swap nums[k] with nums[l] to make the next permutation
            swap(nums[k], nums[l]);

            // Step 5: Reverse the part of the array to the right of k to make it the smallest
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
