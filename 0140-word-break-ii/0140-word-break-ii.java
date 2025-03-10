class Solution {
    // helper function that breaks down the string into words from substrings
    private static List<String> wordBreakRec(String s, List<String> dictionary) {
        // if s is an empty string
        if (s.isEmpty())
            return new ArrayList<String>();

        List<String> res = new ArrayList<String>();

        // Verifying if s can be broken down further
        for (String word : dictionary) {
            // if s does not start with the current word, skip it
            if (!s.startsWith(word))
                continue;
            if (word.length() == s.length())
                res.add(s);
            else {
                // otherwise, break down the remaining part of s and append the current word to each result
                List<String> resultOfTheRest = wordBreakRec(s.substring(word.length()), dictionary);
                for (String item : resultOfTheRest) {
                    item = word + " " + item;
                    res.add(item);
                }
            }
        }
        return res;
    }

    public List<String> wordBreak(String s, List<String> wordDict) {
        // Calling the wordBreakRec function
        return wordBreakRec(s, wordDict);
    }
}