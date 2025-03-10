class Solution {
    public int longestPalindromeSubseq(String s) {
        // Initializing a lookup table of dimensions len(s) x len(s)
        int lookupTable[][] = new int[s.length()][s.length()];

        // Every sequence with one element is a palindrome of length 1
        for (int i = 0; i< s.length(); i++)
            lookupTable[i][i]=1;  
             
        for (int startIndex = s.length(); startIndex >= 0; startIndex--)
            for (int endIndex = startIndex + 1; endIndex < s.length(); endIndex++)
                
                // case 1: elements at the beginning and the end are the same
                if ( s.charAt(startIndex) == s.charAt(endIndex)){
                    lookupTable[startIndex][endIndex] = 2 + lookupTable[startIndex + 1][endIndex - 1];
                }
                
                // case 2: skip one element either from the beginning or the end
                else{
                    lookupTable[startIndex][endIndex]= Math.max(lookupTable[startIndex + 1][endIndex], lookupTable[startIndex][endIndex - 1]);
                }
        return lookupTable[0][s.length()-1];
    }
}





/*
class Solution {
    public static int longestPalindromicSubsequenceRecursive(int[][] lookupTable, String s, int startIndex, int endIndex) {
        if (startIndex > endIndex) 
            return 0;
        
        // Every sequence with one element is a palindrome of length 1
        if (startIndex == endIndex)
            return 1;

        if (lookupTable[startIndex][endIndex] == 0) {
            // case 1: elements at the beginning and the endIndex are the same
            if (s.charAt(startIndex) == s.charAt(endIndex))
                lookupTable[startIndex][endIndex] = 2 + longestPalindromicSubsequenceRecursive(lookupTable, s, startIndex + 1, endIndex - 1);
            // case 2: skip one element either from the beginning or the endIndex
            else {
                int c1 = longestPalindromicSubsequenceRecursive(lookupTable, s, startIndex + 1, endIndex);
                int c2 = longestPalindromicSubsequenceRecursive(lookupTable, s, startIndex, endIndex - 1);
                lookupTable[startIndex][endIndex] = Math.max(c1, c2);
            }
        }
        return lookupTable[startIndex][endIndex];
    }
    public int longestPalindromeSubseq(String s) {
        // Initializing a lookup table of dimensions len(s) x len(s)
        int lookupTable[][] = new int[s.length()][s.length()];
        for (int[] row : lookupTable)  
            Arrays.fill(row, 0); 
        
        return longestPalindromicSubsequenceRecursive(lookupTable, s, 0, s.length() - 1);
    }
}

*/

/*
class Solution {
     public static int longestPalindromicSubsequenceRecursive(String s, int startIndex, int endIndex) {
        if (startIndex > endIndex) return 0;

        // Every sequence with one element is a palindrome of length 1
        if (startIndex == endIndex) return 1;

        // Case 1: elements at the beginning and the end are the same
        if (s.charAt(startIndex) == s.charAt(endIndex))
            return 2 + longestPalindromicSubsequenceRecursive(s, startIndex + 1, endIndex - 1);

        // Case 2: skip one element either from the beginning or the end
        int c1 = longestPalindromicSubsequenceRecursive(s, startIndex + 1, endIndex);
        int c2 = longestPalindromicSubsequenceRecursive(s, startIndex, endIndex - 1);
        return Math.max(c1, c2);
    }

    public int longestPalindromeSubseq(String s) {
        int length = s.length();
        return longestPalindromicSubsequenceRecursive(s, 0, length - 1);
    }
}

*/