class Solution {
    List<String> ans = new ArrayList<>();

    public void dfs(String digits, String[] pad, StringBuilder currString, int idx){

        if(idx == digits.length()){
            ans.add(currString.toString());
            return;
        }

        // Get the letters that the current digit maps to, and loop through them
        // { 0,  1,  2  ,  3   ,    4  ,   5  ,   6  ,    7  ,    8 ,   9   };
        // {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        // Get the letters that the current digit maps to, and loop through them
        String currPadString = pad[digits.charAt(idx) - '0'];
        for (int i = 0; i < currPadString.length(); i++) {
            currString.append(currPadString.charAt(i));  // Append to StringBuilder
            dfs(digits, pad, currString, idx + 1);
            currString.deleteCharAt(currString.length() - 1);  // Backtrack
        }
    }

    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0 || digits == null){
            return ans;
        }
        String[] pad = {"","","abc","def","ghi", "jkl","mno","pqrs","tuv","wxyz"};

        dfs(digits,pad,new StringBuilder(),0);

        return ans;
    }
}