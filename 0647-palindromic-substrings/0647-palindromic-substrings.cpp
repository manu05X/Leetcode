class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;

        // Bottom-up DP approach
        for (int i = n - 1; i >= 0; i--) { // Reverse traversal
            for (int j = i; j < n; j++) { // Forward traversal
                // Base cases: single character or two-character palindrome
                if (s[i] == s[j]) {
                    if (j - i <= 1) { // Single character or two consecutive same characters
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) { // Check if the inner substring is palindrome
                        dp[i][j] = true;
                    }
                }
                
                // If substring s[i:j] is palindrome, count it
                if (dp[i][j]) count++;
            }
        }
        
        return count;
    }
};



/*
class Solution {
public:
    int isPalindrome(const string& s, int l, int r){
        int count = 0;
        // Expand around the center as long as the characters are the same
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            ++count;// Increment the count for the current palindrome
            --l;// Move the left pointer backward
            ++r;// Move the right pointer forward
        }
        return count;
    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            //for(int j = i; j < s.size(); j++){

                count += isPalindrome(s,i,i);//odd
                count += isPalindrome(s, i, i+1);//even
            
        }
        return count;// Return the total count of palindromic substrings
    };
};
*/