class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Sort the 'points' array using a custom comparator
        sort(points.begin(), points.end(), [](const vector<int>& pointA, const vector<int>& pointB) {
            // Calculate the squared Euclidean distance from the origin for pointA
            int distA = pointA[0] * pointA[0] + pointA[1] * pointA[1];
            // Calculate the squared Euclidean distance from the origin for pointB
            int distB = pointB[0] * pointB[0] + pointB[1] * pointB[1];
            // Compare the squared distances to sort the points by distance
            return distA < distB;
        });

        // Construct a vector containing the first 'k' elements from the sorted 'points' array
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
