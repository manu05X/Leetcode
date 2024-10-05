class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();

        int maxLength = 0;
        Map<Character, Integer> mp = new HashMap<>();

        int l = 0;
        // try to extend the range [l, r]
        for(int r = 0; r < n; r++){
            char currChar = s.charAt(r);

            if(mp.containsKey(currChar)){
                 // updating the left if we encounter the char again at right
                l = Math.max(l, mp.get(currChar));
            }

            int currDist = r-l+1; //current gap between r and l
            maxLength = Math.max(maxLength, currDist);

            mp.put(currChar, r+1);
        }



        return maxLength;
    }
}