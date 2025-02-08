class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = nums1.size();
        int m = nums2.size();

        stack<int> st; // Stack to maintain decreasing order of elements.
        vector<int> ans; // Result vector to store answers for nums1.
        unordered_map<int, int> mp; // Map to associate each number with its next greater element.

        // Iterate over each number in nums2 to find the next greater element.
        for (int i = 0; i < m; i++) {
            int elem = nums2[i];

            // If the current element is greater than the top of the stack,
            // the top element's next greater element is found.
            while (!st.empty() && st.top() < elem) {
                mp[st.top()] = elem; // Map the top element of stack to the current element.
                st.pop(); // Remove the top element as its next greater element is found.
            }

            // Push the current element onto the stack.
            st.push(elem);
        }

        // Iterate over each number in nums1 to build the result vector.
        for (int num : nums1) {
            // If the number has a next greater element in the map, add it to the result.
            // If not, add -1 to represent there is no next greater element.
            ans.push_back(mp.count(num) ? mp[num] : -1);
        }

        return ans;
    }
};





/*
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = nums1.size();
        int m = nums2.size();

        stack<int> st; // Stack to maintain the order of elements.
        //vector<int> ans(n,-1);
        vector<int> ans;
        unordered_map<int,int> mp;// Map to associate each number with its next greater element.
        
        // Iterate over each number in nums2 to find the next greater element.
        for(int i = 0; i < m; i++)
        {
            int elem = nums2[i];
            // While there are elements in the stack and the current element
            // is greater than the top element of the stack.
            
            while(!st.empty() && st.top() < elem)
            {// Map the top element of the stack to the current element.
                mp[st.top()] = elem;
                st.pop();// Remove the top element as its next greater element is found.
            }
            // Push the current element onto the stack.
            st.push(elem);
        }

        // Iterate over each number in nums1 to build the result vector.
        // while(!st.empty())
        // {
        //     mp[st.top()] = -1;
        //     st.pop();
        // }

        // for(int i = 0; i < n; i++)
        // {
        //     ans[i] = mp[nums1[i]];
        // }
        // Iterate over each number in nums1 to build the result vector.
        for (int num : nums1) {
            // If the number has a next greater element in the map then add it to the result.
            // If not, add -1 to represent there is no next greater element.
            ans.push_back(mp.count(num) ? mp[num] : -1);
        }

        return ans;
    }
};
*/