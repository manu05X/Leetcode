class Solution {
public:
    static bool compare(const string &s1, const string &s2){
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(), words.end(),compare);
         sort(words.begin(), words.end(),compare);

        unordered_map<string, int> mp;
        int maxLength = 0;

        for(string w : words)
        {
            mp[w] = 1;
            for(int i = 0; i < w.length(); i++){
                string pre = w.substr(0,i) + w.substr(i+1);

                if (mp.find(pre) != mp.end()) 
                {
                    mp[w] = max(mp[w], mp[pre] + 1);
                }
            }
            maxLength = max(maxLength, mp[w]);
        }
        return maxLength;
    }  

/*        
    unordered_map<string, int> dp; // Store the longest chain length for each word.

    int maxLength = 1; // Initialize the maximum chain length to 1.

    for (const string& word : words) 
    {
        // Initialize the chain length for the current word to 1.
        dp[word] = 1;

        // Try removing each character from the word to find predecessors.
        for (int i = 0; i < word.length(); ++i) 
        {
            string predecessor = word.substr(0, i) + word.substr(i + 1);

            if (dp.find(predecessor) != dp.end()) 
            {
                // Update the chain length if a predecessor is found.
                dp[word] = max(dp[word], dp[predecessor] + 1);
            }
        }

        // Update the maximum chain length.
        maxLength = max(maxLength, dp[word]);
    }

    return maxLength;
    }  

    */
};