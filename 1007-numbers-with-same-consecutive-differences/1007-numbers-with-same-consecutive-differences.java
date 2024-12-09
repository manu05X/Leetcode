// class Solution {
//     public int[] numsSameConsecDiff(int n, int k) {
        
//     }
// }


class Solution {
    
    // Helper DFS function to explore all valid numbers
    public void dfs(int digit, int n, int k, List<Integer> ans) {
        // Base case: when n becomes 0, add the current number to the result
        if (n == 0) {
            ans.add(digit);
            return;
        }

        // Loop through all possible digits (0 to 9)
        for (int i = 0; i < 10; i++) {
            // Get the last digit of the current number
            int last_digit = digit % 10;

            // Check if the difference between the last digit and the current digit is exactly k
            if (Math.abs(last_digit - i) == k) {
                // Update the current number by appending the new digit to the right
                digit = digit * 10;

                // Recurse to add the next digit
                dfs(digit + i, n - 1, k, ans);

                // Backtrack: restore the previous number by removing the last digit
                digit = digit / 10;
            }
        }
    }

    // Main function to return all numbers of length n with consecutive digits having a difference of k
     public int[] numsSameConsecDiff(int n, int k) {
        // List to store the result
        List<Integer> ans = new ArrayList<>();

        // Start DFS for numbers starting from each digit from 1 to 9
        for (int i = 1; i < 10; i++) {
            // Call DFS with the starting digit, n - 1 (remaining digits), and k
            dfs(i, n - 1, k, ans);
        }

        // Convert the list to an array
        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }

        // Return the result as an array
        return result;
    }
}