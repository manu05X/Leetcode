class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // check if either rectangle is actually a line
        if(rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] || rec2[1] == rec2[3]){
            return false;
        }

        bool ans = (rec1[2] <= rec2[0] || // left
                    rec1[3] <= rec2[1] || // bottom
                    rec1[0] >= rec2[2] || // right
                    rec1[1] >= rec2[3]);  // top

        return !ans;
    }
};
/*

 [x1, y1, x2, y2], (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner.


No-overlap condition 

r1[x2] ≤ r2[x1]

r1[y2] ≤ r2[y1]

r1[x1] ≥ r2[x2]

r1[y1] ≥ r2[y2]

*/