class Solution {
public:
    int maxArea(vector<int>& height) {
        // Get the size of the input vector
        int n = height.size();

        // Initialize two pointers: one at the beginning and one at the end of the array
        int p1 = 0, p2 = n - 1;

        // Initialize the variable to store the maximum area. Use INT_MIN to start with the smallest value.
        int areaAns = INT_MIN;

        // Loop until the two pointers meet
        while (p1 < p2) {
            // Calculate the distance between the two pointers
            int dist = p2 - p1;

            // Calculate the current area using the shorter height of the two and the distance
            int currArea = dist * min(height[p1], height[p2]);

            // Update the maximum area if the current area is larger
            areaAns = max(currArea, areaAns);

            // Move the pointer pointing to the shorter height inward to potentially find a taller line
            if (height[p1] <= height[p2]) {
                p1++; // Increment the left pointer if the height at p1 is smaller or equal
            } else {
                p2--; // Decrement the right pointer otherwise
            }
        }

        // Return the maximum area found
        return areaAns;
    }
};
























// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int l = 0; 
//         int r = height.size()-1;
//         int maxArea = 0;

//         while(l < r)
//         {
//             int currArea = (min(height[r], height[l]) * (r-l));
//             maxArea = max(currArea, maxArea);

//             if(height[l] < height[r])
//             {
//                 l++;
//             }
//             else{
//                 r--;
//             }
//         }
//         return maxArea;
//     }
// };