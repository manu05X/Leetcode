class Solution {
public:
    string removeOccurrences(string s, string part) {
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);

         // Get the size of the substring 'part'
        int partSize = part.size();
      
        // Find the first occurrence of 'part' in 's'
        int position = s.find(part);
      
        // Continue looping as long as 'part' is found in 's'
        while (position <  s.size()) {
            // Erase 'part' from 's'
            s.erase(position, partSize);
            // Find the next occurrence of 'part' in 's'
            position = s.find(part);
        }
        // Return the modified string with all 'part' occurrences removed
        return s;
    }
};


// dab

// ab