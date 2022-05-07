class Solution {
public:
    bool find132pattern(vector<int>& nums) {
     if (nums.size() < 3) {
            return false;
        }
        stack<int> st;
        vector<int>minArr(nums.size());
        minArr[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            minArr[i] = min(minArr[i-1], nums[i]);
        }
        
        for(int i = nums.size()-1; i > 0; i--)
        {
            if(nums[i] <= minArr[i])
                continue;
            while(!st.empty() and st.top() <= minArr[i])
            {
                st.pop();
            }
            
            if(!st.empty() and st.top() < nums[i])
                return true;
            
            st.push(nums[i]);
        }
        
        return false;   
    }
};