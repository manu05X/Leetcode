class Solution {
public:
    string minWindow(string s, string t) {
      // Step 1: Store the counts of characters for string 't'
        unordered_map<char, int> letters;
        for(auto c : t)  
            letters[c]++; 

        int count = 0; // Number of valid letters in the current window
        int left = 0; // Stores the position of the first character in window
        // Stores location and length of best substring
        int min_length = INT_MAX, min_start = 0;

        //  Step 2 : Iterate over 's'
        for(int right = 0; right<s.length(); right++) 
        {
            // If this character is required, then update count (Add it to the window)
            if(letters[s[right]] > 0) 
                count++;
            // Reduce the count for this character (since we have added this to the window)
            letters[s[right]]--;
            // Step 3: If we have all the valid characters, update substring
            if(count == t.length()) 
            {
                // What exactly are we doing in the loop below?
                //  This piece of code basically makes sure that letters[s[low]] is not negative
                //  Because if it is negative, than that means we have more s[low] than required.
                //  So we have to remove such characters
                while(left < right && letters[s[left]] < 0){ 
                    letters[s[left]]++; // Remove character from window, update count
                    left++; //Shrink the window from the left i.e Update substring window
                }
                //  Step 4: Update substring
                if(min_length > (right - left + 1)){
                    min_start = left; // Set start
                    min_length = right - left + 1; // Set length
                }
            }
        }

        //  Step 5: No substring satisfies 't'
        if(min_length == INT_MAX) return "";

        // Return the best substring
        return s.substr(min_start, min_length);  
    }
};