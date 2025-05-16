class Solution {
    int idx = 0; // Global index to keep track of current parsing position in the input string

    public String decodeString(String s) {
        StringBuilder ans = new StringBuilder(); // To build the decoded string
        int n = s.length();

        // Traverse until end of string or until we hit a closing bracket ']'
        while (idx < n && s.charAt(idx) != ']') {
            if (!Character.isDigit(s.charAt(idx))) {
                // Case 1: Current character is a letter, just append it
                ans.append(s.charAt(idx));
                idx++;
            } else {
                // Case 2: Current character is a digit — start of k[encoded_string]
                int k = 0;

                // Parse the number k (which can be multiple digits)
                while (idx < n && Character.isDigit(s.charAt(idx))) {
                    k = k * 10 + (s.charAt(idx) - '0');
                    idx++;
                }

                // Skip the opening bracket '['
                idx++;

                // Recursively decode the string inside the brackets
                String decoded = decodeString(s);

                // Skip the closing bracket ']'
                idx++;

                // Append the decoded string k times to the result
                while (k-- > 0) {
                    ans.append(decoded);
                }
            }
        }

        // Return the accumulated decoded string for this recursive level
        return new String(ans);
    }
}
