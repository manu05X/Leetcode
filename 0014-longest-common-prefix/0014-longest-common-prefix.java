class Solution {
     public String longestCommonPrefix(String[] strs) 
     {
        if (strs.length == 0) 
            return "";
        String prefix = strs[0]; // flower
        for (int i = 1; i < strs.length; i++)
        {
            // While the current string does not start with the prefix
            while (strs[i].indexOf(prefix) != 0) {
                // Shorten the prefix by removing the last character
                prefix = prefix.substring(0, prefix.length() - 1);
                // If the prefix becomes empty, return an empty string
                if (prefix.isEmpty()) 
                    return "";
            }
        }
        return prefix;
    }
}