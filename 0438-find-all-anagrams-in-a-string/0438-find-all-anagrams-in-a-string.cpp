class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size();
        int np = p.size();
        vector<int> ans;

        if(ns < np){
            return ans;
        }

        vector<int> windowCharCount(26,0);
        vector<int> pCharCount(26,0);

        for(int i = 0; i < np; i++){
            pCharCount[p[i]-'a']++;
            windowCharCount[s[i]-'a']++;
        }

        if (pCharCount == windowCharCount) {
                ans.push_back(0);
            }


        // Slide the window over string s and compare with character counts of p.
        for (int i = np; i < ns; ++i) {
            windowCharCount[s[i] - 'a']++; // Add the current character to the window count.

            // since we added one element to the right, 
            // one element to the left should be discarded.
            windowCharCount[s[i-np] - 'a']--;
          
            // If the window has the same character counts as p, it's an anagram starting at (i - pLength + 1).
            if (pCharCount == windowCharCount) {
                ans.push_back(i - np + 1);
            }
          
            // // Move the window forward by one: decrease the count of the character leaving the window.
            // windowCharCount[s[i - np + 1] - 'a']--;
        }
      
        return ans;
    }
};


/*
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size();
        int np = p.size();
        vector<int> ans;

        if(ns < np){
            return ans;
        }

        vector<int> windowCharCount(26,0);
        vector<int> pCharCount(26,0);

        for(int i = 0; i < np; i++){
            pCharCount[p[i]-'a']++;
        }

        for(int i = 0; i < np-1; i++){
            windowCharCount[s[i]-'a']++;
        }

        // Slide the window over string s and compare with character counts of p.
        for (int i = np - 1; i < ns; ++i) {
            windowCharCount[s[i] - 'a']++; // Add the current character to the window count.
          
            // If the window has the same character counts as p, it's an anagram starting at (i - pLength + 1).
            if (pCharCount == windowCharCount) {
                ans.push_back(i - np + 1);
            }
          
            // Move the window forward by one: decrease the count of the character leaving the window.
            windowCharCount[s[i - np + 1] - 'a']--;
        }
      
        return ans;
    }
};
*/