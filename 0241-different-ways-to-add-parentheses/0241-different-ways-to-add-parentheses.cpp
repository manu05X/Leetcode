class Solution {
public:
    // Function that computes different results by evaluating the expression in different ways
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size(); // Get the length of the expression string

        vector<int> res; // Result vector to store all possible outcomes
        for (int i = 0; i < n; i++) {
            // If the current character is an operator (not a digit), process the expression
            if (expression[i] < '0') {
                // Recursively solve the left side of the expression
                vector<int> v1 = diffWaysToCompute(expression.substr(0, i));
                // Recursively solve the right side of the expression
                vector<int> v2 = diffWaysToCompute(expression.substr(i + 1));

                // Combine the results of left and right sides based on the operator
                for (auto i1 : v1) { // Iterate through the results from the left side
                    for (auto i2 : v2) { // Iterate through the results from the right side
                        switch (expression[i]) {
                            case '+':
                                res.push_back(i1 + i2); // If operator is '+', add the two results
                                break;

                            case '-':
                                res.push_back(i1 - i2); // If operator is '-', subtract the two results
                                break;

                            case '*':
                                res.push_back(i1 * i2); // If operator is '*', multiply the two results
                                break;
                        }
                    }
                }
            }
        }

        // Base case: If no operators were found, meaning the expression is a single number, convert it to an integer and add to result
        if (res.empty()) {
            res.push_back(stoi(expression)); // Convert the expression to an integer and store it in the result vector
        }

        return res; // Return the result vector containing all possible outcomes
    }
};
