class Solution {
public:
    int maxScore(string s) {
        int n = s.size(); // Length of the binary string.
        int one = 0;      // Counter for the number of '1's in the entire string.
        int zero = 0;     // Counter for the number of '0's in the left part of the split.

        int bestAns = INT_MIN; // Variable to track the maximum score.

        // Traverse the string up to the second last character because the right substring
        // must be non-empty (n-1 ensures at least one character in the right substring).
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1') {
                one++;    // Increment the count of '1's for the right substring.
            } else {
                zero++;   // Increment the count of '0's for the left substring.
            }

            // Update the best score so far.
            // Score = number of '0's in the left substring (zero) - number of '1's in the right substring (one).
            bestAns = max(bestAns, zero - one);
        }

        // After the loop, check the last character of the string.
        // If it is '1', increment the total count of '1's in the string.
        if (s[n - 1] == '1') {
            one++;
        }

        // Add the total number of '1's to the best score, as the right substring contributes all remaining '1's.
        return bestAns + one;
    }
};


/*

Algorithm

Initialize ones = 0, zeros = 0, and best to a very small value like negative infinity.
Iterate i from 0 until s.length - 1:
If s[i] == '1', increment ones.
Otherwise, increment zeros.
Update best with zeros - ones if it is larger.
If the final character of s is equal to '1', increment ones.
Return best + ones.


*/