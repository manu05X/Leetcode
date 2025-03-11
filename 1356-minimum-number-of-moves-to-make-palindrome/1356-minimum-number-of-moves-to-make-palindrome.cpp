// Greedy algo
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        if (s.empty()) return 0;  // Edge case: if string is empty, no moves needed.

        int ans = 0;  // Stores the total number of swaps.

        // Process the string until it becomes empty
        while (s.size() > 0) {
            const int i = s.find(s.back());  // Find the first occurrence of the last character.

            if (i == s.size() - 1) {  
                // If the character is unique (appears only once), it must be moved to the center.
                ans += i / 2;  // Move the character towards the middle.
            } else {
                // If a matching pair is found earlier in the string
                ans += i;  // Count swaps needed to move the character to the correct position.
                s.erase(i, 1);  // Remove the matched character from the string.
            }

            s.pop_back();  // Remove the last character (since it has been matched/processed).
        }
        return ans;  // Return the total number of swaps.
    }
};



/*
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();  // Get the length of the string
        int j = n - 1;  // Pointer to the last character
        int moves = 0;  // Counter for the number of swaps

        // Iterate through the string using two pointers approach
        for(int i = 0; i < j; i++) {
            int k = j;  // Start searching for the matching character from the end

            // Find the matching character for s[i] from the right side
            for(; k > i; k--) {
                if(s[i] == s[k]) {  
                    // Once a match is found, shift characters to bring s[k] next to s[i]
                    for(; k < j; k++) {
                        swap(s[k], s[k+1]);  // Swap adjacent characters
                        moves++;  // Count the swap operation
                    }
                    --j;  // Reduce the right pointer since one pair is handled
                    break;
                }
            }

            // If no match is found (meaning this is the middle character in an odd-length palindrome)
            if(k == i) {
                moves += n / 2 - i;  // Move this character to the center
            }
        }

        return moves;  // Return the total number of moves required
    }
};

*/