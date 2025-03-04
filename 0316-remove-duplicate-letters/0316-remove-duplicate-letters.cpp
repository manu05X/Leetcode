/*
Approach: Stack and Greedy
To address the "Remove Duplicate Letters" problem using a stack and greedy algorithm, we lean on the properties of the stack to maintain lexicographical order:

Key Data Structures:
stack: A dynamic data structure to hold characters in the desired order.
seen: A set to track characters already in the stack.
last_occurrence: A dictionary to track the last occurrence of each character in the string.
Enhanced Breakdown:
Initialization:

Initialize the stack, seen set, and last_occurrence dictionary.
Iterate through the string:

For each character, if it's in the seen set, skip it.
If it's not in the seen set, add it to the stack. While adding, compare it with the top character of the stack. If the current character is smaller and the top character appears later in the string, pop the top character.
Output:

Convert the stack to a string and return.
Complexity:
Time Complexity:

The solution iterates over each character in the string once, leading to a time complexity of O(n)O(n)O(n), where n is the length of the string s.
Space Complexity:

The space complexity is O(n)O(n)O(n) due to the stack, seen set, and last_occurrence dictionary.
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        // this will let us know if there are any more instances of s[i] left in s
        unordered_map<char,int> last_seen_mp;
        // this lets us keep track of what's in our solution in O(1) time
        unordered_set<char> seen_set;
        
        for(int i = 0; i < s.size(); i++)
        {
            last_seen_mp[s[i]] = i;
        }

        for(int i =0; i < s.size(); i++)
        {
            char c = s[i];
            // we can only try to add current char in set if it's not already in our set
            // this is to maintain only one of each character
            if(seen_set.find(c) == seen_set.end())//b=0, c=1, a=2 is not in set // b=3 is already in set // c=4 is not in set
            {
                // if the last letter in our solution:
                //     1. exists
                //     2. is greater than curr c so removing it will make the string smaller
                //     3. it's not the last occurrence
                // we remove it from the solution to keep the solution optimal
                while(!st.empty() && c < st.top() && last_seen_mp[st.top()] > i) // a < c && 4 > 1 // a < b && 3 > 0
                {
                    char elm = st.top();
                    seen_set.erase(elm); // remove from set // b,c
                    st.pop(); // remove from stack // b,c
                } // {} {}

                seen_set.insert(c);//b,c //{a,b ,c}
                st.push(c); //b,c //{a,b ,c}
            }
        }

        string res = "";
        while(!st.empty()){
            res = st.top()+res;
            st.pop();
        }
        // reverse the string 
        //reverse(res.begin(), res.end());

        return res;
    }
};

/*


class Solution {
public:
    string removeDuplicateLetters(string s) {
        // cnt for storing frequency of characters
        // vis for marking visited characters
        vector<int> cnt(26,0)  , vis(26,0);
        
        string res = "";
        int n = s.size();
        
        for(int i = 0; i<n; ++i)
            cnt[s[i] - 'a']++;
        
        for(int i = 0; i<n; ++i)
        {
            // decrease cnt of current character
            cnt[s[i] - 'a']--;
            
            // If character is not already
            // in answer
            if(!vis[s[i]- 'a'])
            {
                // Last character > s[i]
                // and its count > 0
                while(res.size() > 0 && res.back() > s[i] && cnt[res.back() - 'a'] > 0)
                {
                    // marking letter visited
                    vis[res.back() - 'a'] = 0;
                    res.pop_back();
                }
                
                // Add s[i] in res and
                // mark it visited
                res += s[i];
                vis[s[i] - 'a'] = 1;
            }
        }
        // return resultant string
        return res;
    }
};
*/