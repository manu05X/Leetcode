class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        if(n < 2)
            return intervals;
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        ans.push_back(intervals[0]);
        int j = 0;
        for(int i = 1; i < n; i++)
        {
            if(ans[j][1] >= intervals[i][0])
            {
                if(ans[j][1] >= intervals[i][1])
                {continue;}
                else
                    ans[j][1] = intervals[i][1];
            }
            else //if(ans[j][1] >= intervals[i][0] && ans[j][1] <= intervals[i][1])
            {
                
                ans.push_back(intervals[i]);
                j++;
            }
            //j++;
            
        }
        
        return ans;
    }
};

// 1 - 6.  3 - 5 - > 1 - 6
// 1 - 6 5 - 8 -> 1 - 8
// 1- 6 7 - 9