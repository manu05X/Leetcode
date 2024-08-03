class Solution {
    public String minRemoveToMakeValid(String s) {
         Stack<Integer> st = new Stack<>();
        StringBuilder res = new StringBuilder(s);

        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(!st.isEmpty() && s.charAt(st.peek()) == '(' && c == ')'){
                st.pop();
            } else if(c == '(' || c == ')') {
                st.push(i);
            }
        }

        while(!st.isEmpty()){
            res.setCharAt(st.pop(), '#');
        }

        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < res.length(); i++){
            if(res.charAt(i) != '#'){
                ans.append(res.charAt(i));
            }
        }

        return ans.toString();
    }
}