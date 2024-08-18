class Solution {
    List<String> ans = new ArrayList<>();
    public void dfs(int n, String s, int open, int close){
        // happy case where s = 2* A means contains equal number of brackets
        if(s.length() == 2*n){
            ans.add(s);
            return;
        }
        // Conditions to continue
        // open count is less than A - we can keep on adding open brackets
        if(open < n){
            dfs(n, s+"(", open+1, close);
        }
        // close count is less than open  - we can keep on adding close brackets
        if(open > close){
            dfs(n, s+")", open, close+1);
        }
    }
    public List<String> generateParenthesis(int n) {
        dfs(n, "", 0, 0);
        return ans;
    }
}