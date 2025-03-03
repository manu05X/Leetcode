class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n; // If there are <=2 points, they are always on a line

        int maxCount = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeMap;
            int duplicate = 0, vertical = 0, currMax = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicate++; // Same point
                    continue;
                }

                if (dx == 0) {
                    vertical++;
                    currMax = max(currMax, vertical);
                    continue;
                }

                int gcdVal = __gcd(dx, dy);
                dx /= gcdVal;
                dy /= gcdVal;

                string slope = to_string(dy) + "/" + to_string(dx);
                slopeMap[slope]++;
                currMax = max(currMax, slopeMap[slope]);
            }

            maxCount = max(maxCount, currMax + duplicate + 1);
        }

        return maxCount;
    }
};
