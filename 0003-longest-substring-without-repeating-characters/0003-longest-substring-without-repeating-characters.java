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

/*
abcabcbb
01234567

currDist = (r-l+1)

l = 0, r = 0, currDist = 1, ans = 1, mp{a:1}
l = 0, r = 1, currDist = 2, ans = 1, mp{a:1, b:2}
l = 0, r = 2, currDist = 3, ans = 3, mp{a:1, b:2, c:3}
l = 1, r = 3, currDist = 3, ans = 3, mp{a:4, b:2, c:3}, as a is repeting so change the left to where it was previously found i.e 1
l = 2, r = 4, currDist = 3, ans = 3, mp{a:4, b:5, c:3} similarly for b=5, l = 2
l = 3, r = 5, currDist = 3, ans = 3, mp{a:4, b:5, c:6} similarly for c=6, l = 3
l = 5, r = 6, currDist = 2, ans = 3, mp{a:4, b:6, c:6} similarly for b=6, l = 5
l = 7, r = 7, currDist = 1, ans = 3, mp{a:4, b:7, c:6} similarly for b=6, l = 7

*/