class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        vector<int> ans;
        
        if (nums.size() == 0) 
        {
            return ans;
        }
        
        if (k > nums.size()) 
        {
            k = nums.size();
        }
        
        for(int i = 0; i < k; i++)
        {
            while(!q.empty() && nums[i] >= nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        
        ans.push_back(nums[q.front()]);
        for(int i = k; i < nums.size();i++)
        {
            while(!q.empty() && nums[i] >= nums[q.back()])
            {
                q.pop_back();
            }
            
            if(!q.empty() && q.front() <= i- k)
                q.pop_front();
            
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        
        return ans;
    }
};