class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        // For the empty pattern, we have one matching.
        if ((s1.length() + s2.length()) != s3.length()) {
            return false;
        }

        // Create a table with an extra row and column to seperate the base cases.
        boolean[][] lookupTable = new boolean[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i < (s1.length() + 1); i++)
            for (int j = 0; j < (s2.length() + 1); j++)
                lookupTable[i][j] = false;

        for (int s1Index = 0; s1Index < s1.length() + 1; s1Index++) {
            for (int s2Index = 0; s2Index < s2.length() + 1; s2Index++) {
                // If 's1' and 's2' are empty, then 's3' must have been empty too.
                if (s1Index == 0 && s2Index == 0) {
                    lookupTable[s1Index][s2Index] = true;
                }
                // Checking the interleaving with 's2' only
                else if ((s1Index == 0) && (s2.charAt(s2Index - 1)) == s3.charAt(s1Index + s2Index - 1)) {
                    lookupTable[s1Index][s2Index] = lookupTable[s1Index][s2Index - 1];

                }
                // Checking the interleaving with 's1' only
                else if ((s2Index == 0) && (s1.charAt(s1Index - 1)) == s3.charAt(s1Index + s2Index - 1)) {
                    lookupTable[s1Index][s2Index] = lookupTable[s1Index - 1][s2Index];
                } else {
                    // If the letter of 's1' and 's3' match, we take whatever is matched till s1Index-1
                    if ((s1Index > 0) && s1.charAt(s1Index - 1) == s3.charAt(s1Index + s2Index - 1)) {
                        lookupTable[s1Index][s2Index] = lookupTable[s1Index - 1][s2Index];
                    }
                    // If the letter of 's2' and 's3' match, we take whatever is matched till s2Index-1 too
                    if ((s2Index > 0) && s2.charAt(s2Index - 1) == s3.charAt(s1Index + s2Index - 1)) {
                        lookupTable[s1Index][s2Index] = lookupTable[s1Index][s2Index] || lookupTable[s1Index][s2Index - 1];
                    }
                }
            }
        }

        return lookupTable[s1.length()][s2.length()];
    }
}