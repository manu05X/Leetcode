class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();

        
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] <= heights[i]){
                st.pop();
            }
            st.push(i);
        }

        vector<int> ans(st.size(), 0);
        int x = st.size()-1;

        while(!st.empty()){
            ans[x] = st.top();
            st.pop();
            x--;
        }
        return ans;

    }
};

/*
[4,2,3,1]
[0,2,3]

4,3,1

4,3,2,1

4

*/

