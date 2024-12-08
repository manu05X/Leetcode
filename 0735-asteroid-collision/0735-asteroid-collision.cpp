class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int astorid : asteroids){
            bool flag = true;

            while(!st.empty() && (st.top() > 0 && astorid < 0)){
                // If the top asteroid in the stack is smaller, then it will explode.
                // Hence pop it from the stack, also continue with the next asteroid in the stack.
                if(abs(st.top()) < abs(astorid)){
                    st.pop();
                    continue;
                } 
                // If both asteroids are the same size, then both asteroids will explode.
                // Pop the asteroid from the stack; also, we won't push the current asteroid to the stack.
                else if(abs(st.top()) == abs(astorid)){
                    st.pop();
                }

                // If we reach here, the current asteroid will be destroyed
                // Hence, we should not add it to the stack
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