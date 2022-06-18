class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // m = (y1-y0)/(x1-x0) = (y2-y1)/(x2-x1) i.e dy/dx = (y2-y1)/(x2-x1)
        // dy*(x2-x1) = dx*(y2-y1) condition should satisfy
        int dy = coordinates[1][1] - coordinates[0][1];
        int dx = coordinates[1][0] - coordinates[0][0];
        
        for(int i = 2; i < coordinates.size(); i++)
        {
            auto p = coordinates[i];
            // dy*(x2-x1) != dx*(y2-y1) 
            if(dx*(p[1] - coordinates[0][1]) != dy*(p[0] - coordinates[0][0]))
                return false;
        }
        
        return true;
    }
};