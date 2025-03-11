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
