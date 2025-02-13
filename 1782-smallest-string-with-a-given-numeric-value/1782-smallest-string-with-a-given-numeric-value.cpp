class Solution {
public:
    string getSmallestString(int n, int k) {
        string result(n, 0);  // Initialize a string of size n with all null characters

        // Start filling the string from the rightmost position (n-1) to left (0)
        for(int pos = n-1; pos >= 0; pos--){
            int add = min(k - pos, 26); // The max we can add at this position is 26
            result[pos] = (char)(add + 'a' - 1); // Convert to corresponding character
            k -= add; // Reduce k by the added value
        }

        return result; // Return the lexicographically smallest string
    }
};