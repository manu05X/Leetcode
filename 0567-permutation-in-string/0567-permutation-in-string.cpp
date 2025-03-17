class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        // If s1 is longer than s2, no permutation can exist
        if (n1 > n2) {
            return false;
        }

        // Frequency arrays for s1 and the current window in s2
        vector<int> freq1(26, 0); // Frequency of characters in s1
        vector<int> freq2(26, 0); // Frequency of characters in the current window of s2

        // Initialize frequency counts for s1 and the first window of s2
        for (int i = 0; i < n1; i++) {
            freq1[s1[i] - 'a']++; // Increment count for s1
            freq2[s2[i] - 'a']++; // Increment count for the first window of s2
        }

        // Compare the frequency counts of the first window
        if (freq1 == freq2) {
            return true;
        }

        // Slide the window over s2
        for (int i = n1; i < n2; i++) {
            // Add the new character to the window
            freq2[s2[i] - 'a']++;
            // Remove the old character from the window
            freq2[s2[i - n1] - 'a']--;

            // Compare the frequency counts
            if (freq1 == freq2) {
                return true;
            }
        }

        // No matching window found
        return false;
    }
};

/*
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 > n2){
            return false;
        }

        vector<int> s1Freq(26, 0);
        vector<int> s2Freq(26, 0);

        for(int i = 0; i < n1; i++){
            s1Freq[s1[i]-'a']++;
            s2Freq[s2[i]-'a']++;
        }

        if(s1Freq == s2Freq){
            return true;
        }


        for(int i = n1; i < n2; i++){
            s2Freq[s2[i]-'a']++;
            s2Freq[s2[i-n2]-'a']--;

            if(s1Freq == s2Freq){
                return true;
            }
        }

        // No matching window found
        return false;
    }
};
*/