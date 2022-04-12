class Solution {
    public int minSteps(String s, String t) {
        int res = 0;
        int[] sCount = new int[26];
        int[] tCount = new int[26];
        
        for(char ch : s.toCharArray()){
            sCount[ch - 'a']++;
        }
        for(char ch : t.toCharArray()){
            tCount[ch - 'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            res += Math.abs(sCount[i] - tCount[i]); 
        }
        return res;
    }
}