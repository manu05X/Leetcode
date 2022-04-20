class Solution {
    public String reverseWords(String s) {
        int n = s.length();
        int i = 0; // begining of word
        String result = new String();
        
        while(i < n)
        { //
            while(i < n && s.charAt(i) == ' ')
                i++;
            if(i >= n)
                break;
            
             int j = i+1; // ending of word
            while(j < n && s.charAt(j) != ' ')
                j++;
            // extracting the word
            String sub = s.substring(i,j);
            
            if(result.length() == 0) 
                result = sub;
            else 
                result = sub + " " + result;
            // pointing to next word
            i = j+1;
        }
        
        return result;
    }
}