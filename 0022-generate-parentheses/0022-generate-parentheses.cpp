class Solution {
public:
vector<string> ans;
void rec(int n, string s,int open, int close)
    {
        // happy case where s = 2* A means contains equal number of brackets
        if (s.size() == 2*n)
        {
            ans.push_back(s);
            return;
        }
        // Conditions to continue
        // open count is less than A - we can keep on adding open brackets
        if (open < n)
            rec(n, s+"(",open + 1, close);

        // close count is less than open  - we can keep on adding close brackets
        if (open > close)
            rec(n, s+")",open, close + 1);
    }
    vector<string> generateParenthesis(int A) {
        rec(A,"", 0, 0);
        return ans;
    }
};