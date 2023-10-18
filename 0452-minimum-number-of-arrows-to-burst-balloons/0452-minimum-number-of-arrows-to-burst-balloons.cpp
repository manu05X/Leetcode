class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0)
            return 0;
        
        // sort by x_end
        sort(begin(points), end(points), [](const vector<int> &o1, const vector<int> &o2) {
            return (o1[1] < o2[1]);
        });

        // at least 1 arrow
        int ans = 1;
        // init cur_end with the first balloon
        int curr_end = points[0][1];
        for(auto p : points) {
            int l = p[0];
            int r = p[1];
            // if cur_end < new_start
            if(curr_end < l){
                // then we need a new arrow
                ans += 1;
                // update curr_end
                curr_end = r;
            }
        }
        return ans;

    }
};