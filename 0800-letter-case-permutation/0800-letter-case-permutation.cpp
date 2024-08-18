class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        dfs(s,0, ans);
        return ans;
    }

    void dfs(string s,int idx, vector<string>& ans) {
        // Base case: If the end of the array is reached, add the current permutation to the list
        if (idx >= s.size()) {
            ans.push_back(s);
            return;
        }
        
        // Recursively call the method to handle the next character without modification
        dfs(s,idx + 1,ans);

        // If the current character is a letter, toggle its case and recurse
        if (isalpha(s[idx])) {
            s[idx] ^= ' ';
           dfs(s,idx + 1,ans);
            s[idx] ^= ' '; // Revert the change for backtracking
        }
    }
};

/*
Understanding XOR Operation with ' '
The ASCII value of space (' ') is 32 (in binary: 0010 0000).
The XOR operation (^) flips bits where there is a 1.

Example 1: Toggling from 'a' to 'A'
'a': In ASCII, 'a' is represented as 01100001 in binary.

ASCII value of 'a': 97 (in binary: 0110 0001)

  01100001   // 'a'
^ 00100000   // ' '
------------
  01000001   // 'A'


Example 2: Toggling from 'A' to 'a'
'A': In ASCII, 'A' is 01000001 in binary.
**' '(space):00100000` in binary.
Apply XOR:

  01000001   // 'A'
^ 00100000   // ' '
------------
  01100001   // 'a'
The result is 'a', so charArray[idx] ^= ' ' converts 'A' to 'a'.


Summary
The XOR with space (' ') flips the 6th bit of the ASCII code.
If the character is lowercase, it becomes uppercase, and vice versa.

*/