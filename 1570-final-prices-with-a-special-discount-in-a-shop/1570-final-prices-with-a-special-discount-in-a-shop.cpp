class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> ans = prices;

        for(int i = 0; i < n; i++){

            while(!st.empty() && prices[st.top()] >= prices[i]){
                ans[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};



/*

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;

        for(int i = n-1; i >= 0; i--){

            while(!st.empty() && prices[st.top()] > prices[i]){
                st.pop();
            }

            if(!st.empty()){
                prices[i]-= prices[st.top()];
                

            } else {
                st.push(i);
            }

        }


        return prices;
    }
};
*/
