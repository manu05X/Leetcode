class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> res = new ArrayList<>();
        
        for(String word : words)
        {
            if(matches(word,pattern))
            {
                res.add(word);
            }
        }
        return res;
    }
    
    private boolean matches(String word, String pattern)
    {
        char[] patternToWord = new char[26];
        char[] wordToPattern = new char[26];
        
        for(int i = 0; i < word.length(); i++)
        {
            char wordChar = word.charAt(i);
            char patternChar = pattern.charAt(i);
            
            if(patternToWord[patternChar-'a'] == 0)
            {
                patternToWord[patternChar-'a'] = wordChar;
            }
            if(wordToPattern[wordChar-'a'] == 0)
            {
                wordToPattern[wordChar-'a'] = patternChar;
            }
            if(patternToWord[patternChar-'a'] != wordChar || wordToPattern[wordChar-'a'] != patternChar)
            {
                return false;
            }
        }
        
        return true;
    }
}