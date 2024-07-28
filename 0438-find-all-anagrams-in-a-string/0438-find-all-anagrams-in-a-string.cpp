class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLength = s.size();
        int pLength = p.size();
        vector<int> startingIndices;

        if (sLength < pLength) {
            return startingIndices;
        }
      
        vector<int> pCharCount(26, 0); 
        vector<int> windowCharCount(26, 0);
      
        for (char c : p) {
            ++pCharCount[c - 'a']; 
        }
       
        for (int i = 0; i < pLength - 1; ++i) {
            ++windowCharCount[s[i] - 'a'];
        }
        
        for (int i = pLength - 1; i < sLength; ++i) {
            ++windowCharCount[s[i] - 'a']; 

            if (pCharCount == windowCharCount) {
                startingIndices.push_back(i - pLength + 1);
            }

            --windowCharCount[s[i - pLength + 1] - 'a'];
        }
      
        return startingIndices; // Return the collected starting indices of anagrams.
   
    }
};