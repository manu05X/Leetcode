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

/*

Algorithm (DFS-Based Approach for Generating Parentheses):
Base Case:
    If the length of the string s equals 2 * n (meaning the string contains exactly n pairs of parentheses), add the string to the result list (ans) and return. This is the stopping condition.

Recursive Cases:
    The algorithm continues to explore different possibilities based on the count of open and close parentheses added so far.
    Add Open Parenthesis:

        If the number of open parentheses (open) is less than n, we can add another open parenthesis '(' to the string. This corresponds to the condition if (open < n). The recursive call then continues with the updated string s and incremented open count.
    Add Close Parenthesis:
        If the number of close parentheses (close) is less than the number of open parentheses (open), we can add a close parenthesis ')'. This ensures that no invalid combination is formed (i.e., it prevents adding more closing brackets than opening brackets). This corresponds to the condition if (open > close). The recursive call continues with the updated string s and incremented close count.

Recursive Depth:
    The recursive process continues until the string reaches a length of 2 * n (i.e., it contains exactly n open and n close parentheses). At this point, the valid combination is added to the result list.

Result:
    After all recursive calls are completed, the list ans will contain all possible valid combinations of n pairs of balanced parentheses.
*/