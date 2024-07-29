class Solution {
    public String minWindow(String s, String t) {
        int n = s.length();
        int m = t.length();

        Map<Character, Integer> dictT = new HashMap<>();
        int count = 0; // Number of valid letters in the current window
        int left = 0; // Stores the position of the first character in window
        // Stores location and length of the best substring
        int min_length = Integer.MAX_VALUE, min_start = 0;

        // Store the counts of characters in 't'
        for(int i = 0; i < m; i++){
            int x = dictT.getOrDefault(t.charAt(i), 0);
            dictT.put(t.charAt(i), x+1);
        }

        for(int right = 0; right < n; right++)
        {
            // If this character is required, then update count
            if(dictT.containsKey(s.charAt(right)) && dictT.get(s.charAt(right)) > 0) {
                count++;
            }
            // Reduce the count for this character (since we have added this to the window)
            dictT.put(s.charAt(right), dictT.getOrDefault(s.charAt(right),0)-1);

            // If we have all the valid characters, update substring
            if(count == m)
            {
                // What exactly are we doing in the loop below?
                //  This piece of code basically makes sure that letters[s[low]] is not negative
                //  Because if it is negative, than that means we have more s[low]s than required.
                //  So we have to remove such characters
                while(left < right && (!dictT.containsKey(s.charAt(left)) || dictT.get(s.charAt(left)) < 0)){
                    dictT.put(s.charAt(left), dictT.getOrDefault(s.charAt(left), 0) + 1);
                    left++;
                }

                // Update substring
                if (min_length > (right - left + 1)) {
                    min_start = left; // Set start
                    min_length = right - left + 1; // Set length
                }

            }
        }

        // No substring satisfies 't'
        if (min_length == Integer.MAX_VALUE) {
            return "";
        }

        // Return the best substring
        return s.substring(min_start, min_start + min_length);
    }
}