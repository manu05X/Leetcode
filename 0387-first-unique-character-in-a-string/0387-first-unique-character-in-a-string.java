class Solution {
    public int firstUniqChar(String s) {
        int n = s.length();
        int[] hm = new int[26];
        char[] charMp = s.toCharArray();

        for(int i = 0; i < n; i++){
            hm[charMp[i]-'a']++;
        }

        for(int i = 0; i < n; i++){
            if(hm[charMp[i]-'a'] == 1){
                return i;
            }
        }
        return -1;

    }
}