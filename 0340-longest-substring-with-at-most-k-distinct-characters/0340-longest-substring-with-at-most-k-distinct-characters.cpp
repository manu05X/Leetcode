
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        int maxLength = 0;

        int left = 0;

        for(int right = 0; right < n; right++){
            //add everyelement to the map with frequency, 
            //if element exists, increase the frequency.
            mp[s[right]]++;
            //we found a substring with more than k distinct elments. 
            //at this point we will shrink the windowStart to elimiate distinct chars.
            while(mp.size() > k){
                //if the frequency is more than 1, decrease it.
                if(mp[s[left]] >= 1){
                    mp[s[left]]--;
                }
                //should be a separate if instead of else, as if after decreasing frequency
                //the final frequency is 0, the element should be removed form the map to reduce total distinct count.
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                //increament windowStart to keep srinking the window.
                left++;
            }
            int currLen = right - left+1;
            maxLength = max(maxLength,currLen);
        }
        return maxLength;
    }
};


/*
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        int maxSize = 0;
        unordered_map<char, int> mp; // Map to store frequency of distinct characters
        
        for (int right = 0; right < n; right++) {
            // Add the current character to the map
            mp[s[right]]++;
            
            // If the number of distinct characters is less than or equal to k, increase maxSize
            if (mp.size() <= k) {
                maxSize++;
            } else {
                // Decrement the frequency of the character at the left end (right - maxSize)
                mp[s[right - maxSize]]--;
                
                // If the frequency becomes 0, remove the character from the map
                if (mp[s[right - maxSize]] == 0) {
                    mp.erase(s[right - maxSize]);
                }
            }
        }

        return maxSize;
    }
};
*/


//ecebaqyee
