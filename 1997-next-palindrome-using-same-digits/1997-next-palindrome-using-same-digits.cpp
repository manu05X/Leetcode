class Solution {
public:
    string nextPalindrome(string num) {
        int n = num.size();
        if (n <= 1) return "";  // Single-digit numbers cannot have a larger palindrome

        // Get the first half of the palindrome
        string firstHalf = num.substr(0, n / 2);
        
        // Find the next lexicographical permutation manually
        int i = firstHalf.size() - 2;
        
        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && firstHalf[i] >= firstHalf[i + 1]) {
            i--;
        }
        
        // If no valid permutation is possible, return ""
        if (i < 0) return "";

        // Step 2: Find the rightmost element greater than firstHalf[i]
        int j = firstHalf.size() - 1;
        while (firstHalf[j] <= firstHalf[i]) {
            j--;
        }
        
        // Step 3: Swap elements at i and j
        swap(firstHalf[i], firstHalf[j]);

        // Step 4: Reverse everything after index i
        reverse(firstHalf.begin() + i + 1, firstHalf.end());

        // Construct the new palindrome
        string nextPal = firstHalf;
        if (n % 2 == 1) {  // If the original number has an odd length, keep the middle character
            nextPal += num[n / 2];
        }
        
        reverse(firstHalf.begin(), firstHalf.end()); // Mirror the first half to construct the palindrome
        nextPal += firstHalf;

        return nextPal;
    }
};
