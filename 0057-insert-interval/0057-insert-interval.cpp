class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            // Case 1: Add intervals that end before the new interval starts
            if(newInterval[0] > intervals[i][1])
            {
                ans.push_back(intervals[i]);
            }
            // Case 2: Add new intervals that end before the intervals starts
            else if(newInterval[1] < intervals[i][0])
            {
                ans.push_back(newInterval);
                for(int j = i; j < n; j++)
                {
                    ans.push_back(intervals[j]);
                }
                return ans;
            }
            else
            // Case 3: Merge overlapping intervals by modified new interval
            {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        //Adding the newInterval
        ans.push_back(newInterval);
        return ans;
    }
};