class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
         // Initializing a table of size s.length + 1
        ArrayList<ArrayList<String>> dpSolutions = new ArrayList<ArrayList<String>>();
        for (int i = 0; i <= s.length(); i++)
            dpSolutions.add(new ArrayList<String>());
        
        // Setting base case
        dpSolutions.get(0).add("");

        // For each substring in the input string, repeat the process.
        for (int i = 1; i <= s.length(); i++) {
            // Iterate over the current substring and break it down into all possible prefixes.
            for (int j = 0; j < i; j++) {
                String prefix = s.substring(j, i);

                // Check if the current prefix exists in word_dict. If it does, we know that it is a valid word
                // and can be used as part of the solution.
                if (wordDict.contains(prefix)) {
                    // Check if any part of the current substring already exists in the dp_solutions array.
                    for (String substrings : dpSolutions.get(j)) {
                        // Merge the prefix with the already calculated results
                        dpSolutions.get(i).add((substrings + " " + prefix).trim());
                    }
                }
            }
        }

        // Returning all the sentences formed using a complete string s.
        return dpSolutions.get(s.length());
    }
}





/*

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
            else {// otherwise, break down the remaining part of s 
                // and append the current word to each result
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

*/