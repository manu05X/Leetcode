class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Step 1: Sort the box types in descending order of units per box
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });

        int maxUnits = 0; // To store the total number of units
        int remainingSpace = truckSize; // Remaining space in the truck

        // Step 2: Traverse through the sorted boxTypes array
        for (auto& box : boxTypes) {
            int boxesToLoad = min(box[0], remainingSpace); // Load as many boxes as possible
            maxUnits += boxesToLoad * box[1]; // Add the corresponding units
            remainingSpace -= boxesToLoad; // Reduce the remaining space

            // Step 3: Break if the truck is full
            if (remainingSpace == 0) break;
        }

        return maxUnits; // Return the maximum units loaded
    }
};


/*

Explanation:
Sorting:

Sort the boxTypes array based on numberOfUnitsPerBox in descending order so we can prioritize the most profitable boxes.
Truck Loading:
    Iterate through the sorted list and calculate how many boxes of each type can be loaded without exceeding the truckSize.
    For each box type:
        Load either all available boxes of that type or as many as the truck can still hold (min(box[0], remainingSpace)).
        Add the corresponding units to maxUnits.

Stopping Condition:
    If the truck's space (remainingSpace) becomes 0, break the loop, as the truck is full.

*/