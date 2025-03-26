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
        {//1st/start element of interval < than 2nd/end element of ans vector so merge
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

/*
Algorithm:

Sort the intervals based on the start times using a custom comparator.
Initialize an empty list (ans) to store the merged intervals.
Add the first interval to the ans list.
Iterate through the sorted intervals starting from the second interval.
    If the start time of the current interval is less than or equal to the end time of the last interval in ans, merge the intervals by updating the end time of the last interval in ans.
    If they don't overlap, add the current interval to ans.
Convert the list ans to a 2D array and return it.
*/