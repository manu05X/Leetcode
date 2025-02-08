class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; // Stack to keep track of remaining asteroids after collisions

        for(int asteroid : asteroids){
            bool flag = true; // Flag to track if the asteroid survives

            // Check if a collision happens (Right-moving asteroid vs Left-moving asteroid)
            while(!st.empty() && (st.top() > 0 && asteroid < 0)){
                // If the top asteroid in the stack is smaller, then it explodes.
                // Continue checking the next asteroid in the stack.
                if(abs(st.top()) < abs(asteroid)){
                    st.pop();
                    continue;
                } 
                // If both asteroids are of the same size, both will explode.
                else if(abs(st.top()) == abs(asteroid)){
                    st.pop();
                }

                // If we reach here, the current asteroid is destroyed (either by equal or larger asteroid)
                // So, we should not add it to the stack.
                flag = false;
                break;
            }

            // If asteroid survives, push it onto the stack.
            if(flag){
                st.push(asteroid);
            }
        }

        // Transfer stack elements to result vector in reverse order.
        vector<int> ans(st.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
