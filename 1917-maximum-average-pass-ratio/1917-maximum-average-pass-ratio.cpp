class Solution {
public:
    // Function to calculate the impact of adding one student to a class
    double getDelta(int pass, int total) {
        double currrentAvg = (double)pass / total; // Current pass ratio
        double afterAvg = (double)(pass + 1) / (total + 1); // Pass ratio after adding one student
        return (afterAvg - currrentAvg); // Difference in pass ratio (impact)
    }

    // Function to maximize the average pass ratio after assigning extra students
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size(); // Number of classes

        // Max-heap to store the classes based on the impact of adding an extra student
        // The heap stores pairs: {impact, {pass, total}}
        priority_queue<pair<double, pair<int, int>>> maxHeap;

        // Initialize the heap with the current impact for each class
        for (int i = 0; i < n; i++) {
            int pass = classes[i][0]; // Students currently passing in the class
            int total = classes[i][1]; // Total students in the class
            maxHeap.push({getDelta(pass, total), {pass, total}}); // Push the impact and class data to the heap
        }

        // Distribute the extra students to maximize the average pass ratio
        while (extraStudents--) {
            // Get the class with the highest impact of adding an extra student
            int pass = maxHeap.top().second.first; // Current number of passing students
            int total = maxHeap.top().second.second; // Current total students in the class

            pass++; // Add an extra passing student
            total++; // Increment total students in the class

            maxHeap.pop(); // Remove the class with the highest impact from the heap
            // Recalculate the impact and push the updated class back into the heap
            maxHeap.push({getDelta(pass, total), {pass, total}});
        }

        // Calculate the final average pass ratio
        double avg = 0.0;
        while (!maxHeap.empty()) {
            int pass = maxHeap.top().second.first; // Passing students in the class
            int total = maxHeap.top().second.second; // Total students in the class

            avg += (double)pass / total; // Add the pass ratio of the class to the total
            maxHeap.pop(); // Remove the class from the heap
        }

        return avg / n; // Return the average pass ratio across all classes
    }
};

/*

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        vector<double> passRatios;

        // Calculate initial pass ratios
        for (int classIndex = 0; classIndex < classes.size(); classIndex++) {
            double initialRatio =
                classes[classIndex][0] / (double)classes[classIndex][1];
            passRatios.push_back(initialRatio);
        }

        while (extraStudents--) {
            vector<double> updatedRatios;

            // Calculate updated pass ratios if an extra student is added
            for (int classIndex = 0; classIndex < classes.size();
                 classIndex++) {
                double newRatio = (classes[classIndex][0] + 1) /
                                  (double)(classes[classIndex][1] + 1);
                updatedRatios.push_back(newRatio);
            }

            int bestClassIndex = 0;
            double maximumGain = 0;

            // Find the class that gains the most from an extra student
            for (int classIndex = 0; classIndex < updatedRatios.size();
                 classIndex++) {
                double gain =
                    updatedRatios[classIndex] - passRatios[classIndex];
                if (gain > maximumGain) {
                    bestClassIndex = classIndex;
                    maximumGain = gain;
                }
            }

            // Update the selected class
            passRatios[bestClassIndex] = updatedRatios[bestClassIndex];
            classes[bestClassIndex][0]++;
            classes[bestClassIndex][1]++;
        }

        // Calculate the total average pass ratio
        double totalPassRatio = 0;
        for (double passRatio : passRatios) {
            totalPassRatio += passRatio;
        }

        return totalPassRatio / classes.size();
    }
};

*/