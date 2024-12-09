class Solution {
public:
    // Depth First Search (DFS) helper function to generate numbers with the required property
    void dfs(int digit, int n, int k, vector<int>& ans) {
        // Base case: when the length n becomes 0, we add the current number to the answer list
        if (n == 0) {
            ans.push_back(digit);
            return;
        }

        // Loop over all digits (0 to 9) to explore possible next digits
        for (int i = 0; i < 10; i++) {
            // Get the last digit of the current number
            int last_digit = digit % 10;

            // Check if the difference between the last digit and the current digit is exactly k
            if (abs(last_digit - i) == k) {
                // Update the current number by appending the new digit to the right
                digit = digit * 10;

                // Recurse to add the next digit to the current number
                dfs(digit + i, n - 1, k, ans);

                // Backtrack: restore the previous number by dividing by 10 (remove the last digit)
                digit = digit / 10;
            }
        }
    }

    // Function to return all numbers of length n with consecutive digits having a difference of k
    vector<int> numsSameConsecDiff(int n, int k) {
        // List to store the result
        vector<int> ans;

        // Start DFS for numbers starting from each digit from 1 to 9
        for (int i = 1; i < 10; i++) {
            // For each starting digit, invoke DFS with the remaining length (n-1) and difference k
            dfs(i, n - 1, k, ans);
        }

        // Return the final result with all valid numbers
        return ans;
    }
};
