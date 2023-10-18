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
            // new_start
            int l = p[0];
            //new_end
            int r = p[1];
            // if cur_end less than new_start
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

/*
    0.   1.    2.     3. 
[[1,6],[2,8],[7,12],[10,16]]

i = 0,1,2,3

l = 1,2,7,10
r = 6,8,12,16
curr_end = 6,6,12,12
ans = 1,1,2,2

return ans = 1

*/