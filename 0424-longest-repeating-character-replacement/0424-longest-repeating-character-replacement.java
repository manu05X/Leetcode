class Solution {
    public int characterReplacement(String s, int k) {
        int n = s.length();
        int[] charCount = new int[26];
        int left = 0;
        int maxCharCount = 0;
        int longestReplacementCount = 0;

        for(int right = 0; right < n; right++){
            charCount[s.charAt(right)-'A']++;
            maxCharCount = Math.max(maxCharCount, charCount[s.charAt(right)-'A']);

            int currLength = right-left+1;

            if(currLength - maxCharCount > k){
                charCount[s.charAt(left)-'A']--;
                left++;

                currLength = right-left+1;
            }

            longestReplacementCount = right-left+1;
        }

        return longestReplacementCount;
    }
}