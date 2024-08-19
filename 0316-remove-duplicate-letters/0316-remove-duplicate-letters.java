/*
Approach: Count and Visited Array
To address the "Remove Duplicate Letters" problem using a count and visited array, we leverage the frequency of each character:

Key Data Structures:
count: A dictionary to hold the frequency of each character.
result: A list to hold the final characters in the desired order.
visited: A set to track characters already in the result.
Enhanced Breakdown:
Calculate Frequencies:

Compute the frequency of each character in the string.
Iterate through the string:

For each character, decrease its count. If it's in the visited set, skip it.
If it's not in the visited set, add it to the result. While adding, compare it with the last character in the result. If the current character is smaller and the last character appears later in the string, remove the last character.
Output:

Convert the result list to a string and return.
Complexity:
Time Complexity:

The solution iterates over each character in the string once, leading to a time complexity of O(n)O(n)O(n), where n is the length of the string s.
Space Complexity:

The space complexity is O(n)O(n)O(n) due to the count dictionary, result list, and visited set.
 */
class Solution {
    public String removeDuplicateLetters(String s) {
        Stack<Character> st = new Stack<>();
        Map<Character, Integer> mp = new HashMap<>();
        HashSet<Character> seen = new HashSet<>();

        for(int i = 0; i < s.length(); i++){
            // mp.put(s.charAt(i), i);
            mp.put(s.charAt(i), i);
        }

        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);

            if(!seen.contains(c)){

                while(!st.isEmpty() && c < st.peek() && mp.get(st.peek()) > i){
                    char x = st.peek();
                    seen.remove(x);
                    st.pop();
                }


                seen.add(c);
                st.push(c);
            }
        }

        StringBuilder sb = new StringBuilder(st.size());

        for(Character c : st){
            sb.append(c.charValue());
        }

        return sb.toString();
    }
}