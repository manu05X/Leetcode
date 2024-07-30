class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
         // toBeRemoved[0] is the start of the interval to be removed, toBeRemoved[1] is the end
        int removeStart = toBeRemoved[0];
        int removeEnd = toBeRemoved[1];

        for(auto& x : intervals)
        {
            int start = x[0], end = x[1];
            // Check if the current interval is completely outside the toBeRemoved interval
            if(start >= removeEnd || end <= removeStart){
                // Add interval to the result as it doesn't overlap with toBeRemoved
                ans.push_back(x);
            }
            else
            {
                // Check if part of the interval is before toBeRemoved
                if(start < removeStart){
                    ans.push_back({start, removeStart});
                }
                 // Check if part of the interval is after toBeRemoved
                if(end > removeEnd){
                    ans.push_back({removeEnd, end});
                }
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/remove-interval/description