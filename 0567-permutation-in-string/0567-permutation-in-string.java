class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int l1 = s1.length();  // Length of s1
        int l2 = s2.length();  // Length of s2

        // If s1 is longer than s2, permutation is not possible
        if (l1 > l2) {
            return false;
        }

        int[] charCount = new int[26]; // Frequency array for characters 'a' to 'z'

        // Initialize the frequency array for the first 'l1' characters in s1 and s2
        for (int i = 0; i < l1; i++) {
            charCount[s1.charAt(i) - 'a']--;  // Decrease count for s1
            charCount[s2.charAt(i) - 'a']++;  // Increase count for s2 (initial window)
        }

        // Count how many different characters exist in the window
        int diffCount = 0;
        for (int x : charCount) {
            if (x != 0) {
                diffCount++;
            }
        }

        // If no difference, then s1's permutation is found in s2
        if (diffCount == 0) {
            return true;
        }

        // Sliding window: shift window from left to right
        for (int i = l1; i < l2; i++) {
            int idx1 = s2.charAt(i - l1) - 'a'; // Old character (to be removed)
            int idx2 = s2.charAt(i) - 'a';      // New character (to be added)

            // Adding new character to the window
            if (charCount[idx2] == 0) {
                diffCount++; // If it was zero, we now introduce a difference
            }
            charCount[idx2]++; // Increase its count
            if (charCount[idx2] == 0) {
                diffCount--; // If it becomes zero again, we remove a difference
            }

            // Removing old character from the window
            if (charCount[idx1] == 0) {
                diffCount++; // If it was zero, we now introduce a difference
            }
            charCount[idx1]--; // Decrease its count
            if (charCount[idx1] == 0) {
                diffCount--; // If it becomes zero again, we remove a difference
            }

            // If all character differences are zero, we found a permutation
            if (diffCount == 0) {
                return true;
            }
        }

        // No permutation found
        return false;
    }
}



/*
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
*/