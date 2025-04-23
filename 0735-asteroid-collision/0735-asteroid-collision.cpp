class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++){
            int curr = asteroids[i];
            bool explode = false;

            while(!st.empty() && (curr < 0 && st.top() > 0)){
                if(abs(st.top()) < abs(curr)){
                    st.pop();
                    continue;
                } else if(abs(st.top()) == abs(curr)){
                    st.pop();
                }

                explode = true;
                break;
            }

            if(!explode){
                st.push(curr);
            }
        }

        vector<int> ans(st.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};