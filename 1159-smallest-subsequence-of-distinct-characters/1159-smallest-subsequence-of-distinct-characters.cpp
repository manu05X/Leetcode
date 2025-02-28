// class Solution {
// public:
//     string smallestSubsequence(string s) 
//     {
//         string res = "";
//         int last[26] = {}, seen[26] = {}, n = s.size();
//         for (int i = 0; i < n; ++i)
//             last[s[i] - 'a'] = i;
//         for (int i = 0; i < n; ++i) 
//         {
//             if (seen[s[i] - 'a']++) 
//                 continue;
//             while (!res.empty() && res.back() > s[i] && i < last[res.back() - 'a']){
//                 seen[res.back() - 'a'] = 0;
//                 res.pop_back();
//             }
            
//             res.push_back(s[i]);
//         }
//         return res;
//     }
// };


class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;  // Stack to store characters
        unordered_set<char> seen;  // Track characters in the stack
        unordered_map<char, int> last_seen;  // Store last occurrence of each character

        // Fill last_seen with the last index of each character
        for (int i = 0; i < s.size(); i++) {
            last_seen[s[i]] = i;
        }

        // Iterate through the string
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // If character is already in the result, skip it
            if (seen.find(c) != seen.end()) continue;

            // Remove characters from stack if:
            // - They are greater than current character `c`
            // - They appear later in the string (can be re-added later)
            while (!st.empty() && c < st.top() && last_seen[st.top()] > i) {
                seen.erase(st.top());  // Remove from set
                st.pop();  // Remove from stack
            }

            // Add current character to stack and mark it as seen
            st.push(c);
            seen.insert(c);
        }

        // Build the result from stack
        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};
