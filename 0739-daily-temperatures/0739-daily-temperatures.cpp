class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = t.size();
        vector<int>ans(n,0);

        for(int i=n-2;i>=0;i--){
            int top = i+1;

            for( ;top<n && t[i] >= t[top];top += ans[top]){
                if(ans[top] == 0){
                    top = n;
                    break;
                }
            }
            if(top<n)
                ans[i] = top-i;
        }
        return ans;
    }
};