class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // Get the size of the array
        int n = nums.size();

        // Sort the array to group close elements together
        sort(nums.begin(), nums.end());
        
        // Start the first subsequence with the first element
        int x = nums[0];
        int ans = 1; // At least one subsequence is needed

        // Iterate through the array
        for(int i = 1; i < n; i++) {
            // If the current element fits in the current subsequence
            if(nums[i] - x <= k) {
                continue; // Continue adding elements to the current subsequence
            } else {
                // Start a new subsequence
                x = nums[i];
                ans++; // Increment the subsequence count
            }
        }

        // Return the total number of subsequences
        return ans;
    }
};


/*

We talked about subsequences briefly in the arrays and strings chapter, but as a reminder, a subsequence is a group of elements from the array that keep their order. They're like subarrays, but the elements don't need to be adjacent.

In this problem, for each subsequence, we only care about the maximum and minimum value. The actual order of the elements in the subsequence doesn't matter. Without the order requirement, subsequence is the same as subset. We also spoke about subsets briefly, but a subset is just any set of elements from the array.

What is the best way to group the elements? We want to minimize the number of groups, so we want to maximize the number of elements in the groups. Let's say we start with the smallest number in the input x. We want all elements in the range [x, x + k] to be grouped. It doesn't make sense for any of these elements to not be in the group - let's say we decided to exclude x + k - 1. Then, the next group would have to start at a smaller number. This limits the range of elements that can be grouped, which goes against what we want.

Thus, it's best to greedily take all elements within the range [x, x + k] for the smallest number x. After that, we can "erase" those numbers from the array, and we have the same problem again with a different x. What is the best way to execute this? Sort the array and iterate over it. Because we logically reduced subsequences to subsets, sorting doesn't change anything.


*/