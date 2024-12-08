class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int astorid : asteroids){
            bool flag = true;

            while(!st.empty() && (st.top() > 0 && astorid < 0)){
                if(abs(st.top()) < abs(astorid)){
                    st.pop();
                    continue;
                } else if(abs(st.top()) == abs(astorid)){
                    st.pop();
                }

                flag = false;
                break;
            }

            if(flag){
                st.push(astorid);
            }
        }

         // Add the asteroids from the stack to the vector in the reverse order.
        vector<int> ans(st.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};