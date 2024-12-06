import java.util.HashSet;
import java.util.Set;

class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        // Create a HashSet to store all banned numbers for quick lookup.
        Set<Integer> setBanned = new HashSet<>();
        for (int num : banned) {
            setBanned.add(num);
        }

        int count = 0; // Initialize count to keep track of valid numbers included.
        
        // Iterate through numbers from 1 to n.
        for (int i = 1; i <= n; i++) {
            // Skip the number if it is in the banned set.
            if (setBanned.contains(i)) {
                continue;
            }

            // If adding the current number exceeds maxSum, return the count.
            if (maxSum - i < 0) {
                return count;
            }

            // Deduct the current number from maxSum.
            maxSum -= i;

            // Increment the count since this number is included.
            count++;
        }

        // Return the total count of numbers included.
        return count;
    }
}
