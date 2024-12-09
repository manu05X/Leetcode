class Solution {
public:
    void dfs(int digit, int n, int k, vector<int>& ans){
        if(n == 0){
            ans.push_back(digit);
            return;
        }

        for(int i = 0; i < 10; i++){
            int last_digit = digit % 10;

            if(abs(last_digit - i) == k){
                digit = digit*10;
                dfs(digit+i, n-1, k, ans);

                digit = digit/10;
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;

        for(int i = 1; i < 10; i++){
            dfs(i, n-1, k, ans);
        }

        return ans;
    }
};