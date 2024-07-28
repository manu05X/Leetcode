class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int l1 = s1.length();
        int l2 = s2.length();

        if(l1 > l2){
            return false;
        }

        int[] charCount = new int[26];

        for(int i = 0; i < l1; i++){
            charCount[s1.charAt(i)-'a']--;
            charCount[s2.charAt(i)-'a']++;
        }

        //count of diff char in s1 and s2
        int diffCount = 0;
        for(int x : charCount){
            if(x != 0){
                diffCount++;
            }
        }

        if(diffCount == 0){
            return true;
        }

        for(int i = l1; i < l2; i++){
            int idx1 = s2.charAt(i -l1)-'a'; //Old character to be removed from window
            int idx2 = s2.charAt(i)-'a'; //new character to be added from window

            //1--> Adding newChar to window
            // Before updating charCount for the new character check if its count is 0
            if(charCount[idx2] == 0){
                diffCount++;
            }
            // Add the new character as we move the window
            charCount[idx2]++;

            if(charCount[idx2] == 0){
                diffCount--;
            }

            //2--> Adding old char to window
            //check if its 0 then increment diffCount
            if(charCount[idx1] == 0){
                diffCount++;
            }
            // Remove the old character as we move the window
            charCount[idx1]--;

            if(charCount[idx1] == 0){
                diffCount--;
            }

            // If all deltas are zero, s1's permutation is found in s2.
            if (diffCount == 0) {
                return true;
            }
        }
        // If we reach here, no permutation of s1 is found in s2.
        return false;

    }
}