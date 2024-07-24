class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int n = s.length();
        // Initialize a map to store character counts.
        Map<Character, Integer> mp = new HashMap<>();

        int maxLength=0;
        int left=0;

        for(int i =0;i < n; i++){
            // Add the current character to the map and update its count.
            mp.put(s.charAt(i), mp.getOrDefault(s.charAt(i),0)+1);

            // we found a substring with more than k distinct elements.
            // at this point we will shrink the windowStart to eliminate distinct chars.
            while(mp.size()>k)
            {
                // Get the leftmost character in the window.
                char leftChar = s.charAt(left);
                // if the frequency is more than 1, decrease it.
               if (mp.get(leftChar) > 1) {
                    // Decrease the count if it's more than 1.
                    mp.put(leftChar, mp.get(leftChar) - 1);
                } else {
                    // should be a separate if instead of else, as if after decreasing frequency
                    // the final frequency is 0, the element should be removed from the map to reduce total distinct count.
                    mp.remove(leftChar); 
                }
                left++; // Move the left boundary to the right.
            }

            // Calculate the current window length.
            int currCharlen = i-left+1;
            // Return the maximum length found.
            maxLength = Math.max(maxLength, currCharlen);
        }

        return maxLength;
    }
}