/*
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();

        int maxLength = 0;
        Map<Character, Integer> mp = new HashMap<>();

        int l = 0;
        // try to extend the range [l, r]
        for(int r = 0; r < n; r++){
            char currChar = s.charAt(r);

            if(mp.containsKey(currChar)){
                 // updating the left if we encounter the char again at right
                l = Math.max(l, mp.get(currChar));
            }

            int currDist = r-l; //current gap between r and l
            maxLength = Math.max(maxLength, currDist);

            mp.put(currChar, r);
        }



        return maxLength;
    }
}
*/

/*
Why the First Code Does Not Work

The first implementation fails primarily due to two reasons:
    - Off-by-One Error: The calculation of currDist as r - l does not account for the length of the substring correctly. It should always include both endpoints (i.e., from l to r inclusive), which is why adding 1 is necessary.

    - Incorrect Indexing in Map: By storing just r in the map, when a character is repeated, it can lead to an incorrect update of l, potentially causing it to point to an index that is not valid for forming a substring. The second implementation avoids this by storing r + 1, ensuring that when we encounter a duplicate character, we move l correctly beyond that character.

*/


class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();

        int maxLength = 0;
        Map<Character, Integer> mp = new HashMap<>();

        int l = 0;
        // try to extend the range [l, r]
        for(int r = 0; r < n; r++){
            char currChar = s.charAt(r);

            if(mp.containsKey(currChar)){
                 // updating the left if we encounter the char again at right
                l = Math.max(l, mp.get(currChar));
            }

            int currDist = r-l+1; //current gap between r and l
            maxLength = Math.max(maxLength, currDist);

            mp.put(currChar, r+1);
        }
        return maxLength;
    }
}