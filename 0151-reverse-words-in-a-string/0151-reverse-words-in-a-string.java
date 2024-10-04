class Solution {
    public String reverseWords(String s) {
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