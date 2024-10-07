class Solution {
    public String removeDuplicates(String s) {
        int n = s.length();

        Stack<Character> st = new Stack<>();

        for(int i = 0; i < n; i++){
            if(!st.isEmpty()){
                if(st.peek() == s.charAt(i)){
                    st.pop();
                } else {
                    st.push(s.charAt(i));
                }
            } else {
                st.push(s.charAt(i));
            }
        }
        StringBuilder ans = new StringBuilder("");

        while(!st.isEmpty()){
            ans.append(st.pop());
        }

        return ans.reverse().toString();
    }
}

/*
class Solution {
    public String removeDuplicates(String s) {
        //int n = s.length();

        StringBuilder ans = new StringBuilder();

        for(char x : s.toCharArray()){
            int m = ans.length();

            if(m > 0 && ans.charAt(m-1) == x){
                ans.deleteCharAt(m-1);
            } else {
                ans.append(x);
            }
        }

        return ans.toString();
    }
}
*/