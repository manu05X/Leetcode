class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();

        if(n != m) return false;

        int[] freq = new int[26];
        int numDiff = 0;

        for(int i = 0; i < n; i++){
            if(s1.charAt(i) != s2.charAt(i)){
                numDiff++;

                if(numDiff > 2){
                    return false;
                }
            }

            freq[s1.charAt(i) - 'a']++;
            freq[s2.charAt(i) - 'a']--;
        }

        int count = 0;

        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                count++;
            }
        }

        if(count <= 1){
            return true;
        } else {
            return false;
        }
    }
}