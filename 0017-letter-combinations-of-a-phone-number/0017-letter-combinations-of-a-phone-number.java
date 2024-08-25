class Solution {
    List<String> ans = new ArrayList<>();

    public void dfs(String digits, String[] pad, String currString, int idx){

        if(idx == digits.length()){
            ans.add(currString);
            return;
        }

        String currPadString = pad[digits.charAt(idx)-'0'];
        for(int i = 0; i < currPadString.length(); i++){
            dfs(digits,pad,currString + currPadString.charAt(i),idx+1);
        }
    }

    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0 || digits == null){
            return ans;
        }
        String[] pad = {"","","abc","def","ghi", "jkl","mno","pqrs","tuv","wxyz"};

        dfs(digits,pad,"",0);

        return ans;
    }
}