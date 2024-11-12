class Solution {
    public int minSteps(String s, String t) {
        int[] charCount = new int[26];

        for(int i = 0; i < s.length(); i++){
            charCount[s.charAt(i)-'a']++;
            charCount[t.charAt(i)-'a']--;
        }

        int ans= 0;

        for(int i = 0; i < 26; i++){
            ans += Math.max(0, charCount[i]);
        }

        return ans;

    }
}