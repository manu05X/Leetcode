class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        if(n < 2)
            return intervals;
        //sort the interval in increasing order
        sort(intervals.begin(), intervals.end());
        //push the first interval in ans
        ans.push_back(intervals[0]);

        int j = 0;// ans iterator
        for(int i = 1; i < n; i++)
        {//first element of interval < than 2nd element of ans vector so merge
            if(intervals[i][0] <= ans[j][1])
            {// change the ans 2nd element by comparing interval's 2nd and ans 2nd element
                ans[j][1] = max(intervals[i][1],ans[j][1]);
            }
            else
            {
                j++;
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};