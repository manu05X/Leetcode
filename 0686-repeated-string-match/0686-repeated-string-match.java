class Solution {
    public int repeatedStringMatch(String a, String b) {
        StringBuilder s = new StringBuilder();  // Use StringBuilder to build the repeated string
        int count = 0;  // Initialize counter to track how many times `a` has been added to `s`

        // Keep appending `a` to `s` until `s` becomes at least as long as `b`
        while (s.length() < b.length()) {
            s.append(a);  // Append string `a` to `s`
            count++;      // Increment the count of repetitions
        }

        // Check if `b` is a substring of `s`
        if (s.indexOf(b) != -1) {
            return count;  // If found, return the number of repetitions
        }

        // Append `a` one more time to `s`
        s.append(a);
        count++;  // Increment the count for one more repetition

        // Check again if `b` is now a substring of the updated `s`
        if (s.indexOf(b) != -1) {
            return count;  // If found, return the number of repetitions
        }

        // If `b` is still not a substring, return -1 indicating `b` cannot be formed
        return -1;
    }
}