class Solution {
public:
    string decodeString(string s) {
        int idx = 0;  // Initialize index to start from the beginning of the string
        return decodeString(s, idx);  // Call the helper function with the starting index
    }
    
    // Helper recursive function to decode the string
    string decodeString(const string& s, int& idx) {
        string res;  // This will store the decoded string for current level
        
        // Loop until we reach the end of string or encounter a closing bracket ']'
        while(idx < s.length() && s[idx] != ']') {
            // If current character is not a digit, it's part of the normal string
            if(!isdigit(s[idx])) {
                res += s[idx++];  // Add to result and move to next character
            }
            else {
                // Extract the number (k) which tells how many times to repeat the substring
                int k = 0;
                while(idx < s.length() && isdigit(s[idx])) {
                    k = k * 10 + (s[idx++] - '0');  // Build the number digit by digit
                }
                
                idx++;  // Skip the '[' character after the number
                string decod = decodeString(s, idx);  // Recursively decode the substring inside []
                
                idx++;  // Skip the ']' character after the decoded substring
                
                // Append the decoded substring k times to the result
                while(k-- > 0) {
                    res += decod;
                }
            }
        }
        return res;  // Return the decoded string for current level
    }
};