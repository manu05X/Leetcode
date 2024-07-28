class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
      
        // If length of s1 is greater than s2, permutation is not possible
        if (len1 > len2) {
            return false;
        }

        // Vector to store character counts
        vector<int> charCount(26, 0);
      
        // Initialize the character count vector with the first len1 characters
        for (int i = 0; i < len1; ++i) {
            --charCount[s1[i] - 'a']; // Decrement for characters in s1
            ++charCount[s2[i] - 'a']; // Increment for characters in the first window of s2
        }

        // Calculate the difference count
        int diffCount = 0;
        for (int count : charCount) {
            if (count != 0) {
                ++diffCount;
            }
        }
      
        // If diffCount is zero, a permutation exists in the first window
        if (diffCount == 0) {
            return true;
        }

        // Slide the window over s2 and update the counts and diffCount
        for (int i = len1; i < len2; ++i) {
            int index1 = s2[i - len1] - 'a'; // Index for the old character in the window to be removed
            int index2 = s2[i] - 'a'; // Index for the new character in the window to be added

            //1--> for new charater
            // Before updating charCount for the new character check if its 0
            if (charCount[index2] == 0) {
                ++diffCount; // increment it
            }
            ++charCount[index2]; // Added the new character in the window

            // After updating charCount for the new character check if charCount becomes 0
            if (charCount[index2] == 0) {
                --diffCount; //then decrement it
            }


            //2--> For Old character
            // Before updating charCount for the old character
            if (charCount[index1] == 0) {
                ++diffCount;
            }
            --charCount[index1]; // Remove the old character as we move the window

            // After updating charCount for the old character
            if (charCount[index1] == 0) {
                --diffCount;
            }

            // If the diffCount is zero after the updates, a permutation is found
            if (diffCount == 0) {
                return true;
            }
        }

        // No permutation was found
        return false;
    }
};