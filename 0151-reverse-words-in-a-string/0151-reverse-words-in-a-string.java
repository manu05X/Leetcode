/*
class Solution {
    // A function that reverses characters from startRev to endRev in place
    private static void strRev(char[] str, int startRev, int endRev) {
        while (startRev < endRev) {
            char temp = str[startRev];
            str[startRev] = str[endRev];
            str[endRev] = temp;
            startRev++;
            endRev--;
        }
    }

    public String reverseWords(String s) {
         // Replace multiple spaces with a single space and trim leading/trailing spaces
        s = s.replaceAll("\\s+", " ").trim();
        
        // Convert the cleaned string into a character array for manipulation
        char[] charArray = s.toCharArray();
        int strLen = charArray.length - 1;

        strRev(charArray, 0, strLen);

        for (int start = 0, end = 0; end <= strLen; ++end) {
            if (end == strLen || charArray[end] == ' ') {
                int endIdx = (end == strLen ) ? end : end - 1;
                strRev(charArray, start, endIdx);
                start = end + 1;
            }
        }
        return new String(charArray);
    }
}

*/



class Solution {
    public String reverseWords(String s) {
        // "\\s+" is a regular expression that matches one or more whitespace characters1. 
        //The \s represents any whitespace character (space, tab, newline, etc.), and the + means "one or more occurrences
        //  First removes leading and trailing whitespace from the string s and then splits the string into an array of substrings using whitespace as a delimiter.
        String[] str = s.trim().split("\\s+");

        String out = "";

        // for(int i = str.length - 1; i > 0; i--){
        //     System.out.print(str[i]);
        // }

        // System.out.println(str[0]);

        for(int i = str.length - 1; i > 0; i--){
            out += str[i]+ " ";
        }

        return out + str[0];
    }
}

/*
class Solution {
    public void reverse(StringBuilder sb, int left, int right) 
    {
        while (left < right) {
            char tmp = sb.charAt(left);
            sb.setCharAt(left++, sb.charAt(right));
            sb.setCharAt(right--, tmp);
        }
  }
    public String reverseWords(String s) {
        int h = s.length()-1;
        int i = 0;
        String ans = "";

        while(h >= 0){
            while(h >= 0 && s.charAt(h) == ' '){
                h--;
            }
            
            i = h;
            String temp = "";
            while(i>=0 && s.charAt(i) != ' '){
                temp += s.charAt(i);
                i--;
            }

            int left = 0;
            int right = temp.length()-1;
            while (left < right) 
            {
                char tmp = temp.charAt(left);
                temp.setCharAt(left++, temp.charAt(right));
                temp.setCharAt(right--, tmp);
            }

            //reverse(temp, 0, temp.length()-1);

            if(temp.size()){
                ans += ans.size() == 0 ? temp : " "+temp;
            }
            h = i;
        }
        ans = ans.substr(0, ans.length());
        return ans;
    }
}
*/