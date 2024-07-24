class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int n = s.length();
        Map<Character, Integer> mp = new HashMap<>();

        int maxLength=0;
        int left=0;

        for(int i =0;i < n; i++){
            mp.put(s.charAt(i), mp.getOrDefault(s.charAt(i),0)+1);

            // we found a substring with more than k distinct elements.
            // at this point we will shrink the windowStart to eliminate distinct chars.
            while(mp.size()>k)
            {
                // if the frequency is more than 1, decrease it.
                char leftChar = s.charAt(left);
               if (mp.get(leftChar) > 1) {
                    mp.put(leftChar, mp.get(leftChar) - 1);
                } else {
                    // should be a separate if instead of else, as if after decreasing frequency
                    // the final frequency is 0, the element should be removed from the map to reduce total distinct count.
                    mp.remove(leftChar);
                }
                left++;
            }

            int currCharlen = i-left+1;
            maxLength = Math.max(maxLength, currCharlen);
        }

        return maxLength;
    }
}