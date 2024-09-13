class Solution {
public:
    int calculate(string s) {
        stack<int> operands;  // Stack to hold numbers and signs (as integer)
        int result = 0;       // Accumulator for the current result
        int sign = 1;         // Current sign, starts with positive
        int n = s.size();     // Size of the input string
      
        for (int i = 0; i < n; ++i) {
            // If the character is a digit, it could be part of a multi-digit number.
            if (isdigit(s[i])) {
                int num = 0; // Initialize the number to be 0
                // Construct the number from the subsequent digits
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                // Add/Subtract the number to/from the current result
                result += sign * num;
                // Since the loop will increment i after, we decrease it here
                --i;
            } else if (s[i] == '+') {
                sign = 1;  // Set sign to positive for the next number
            } else if (s[i] == '-') {
                sign = -1; // Set sign to negative for the next number
            } else if (s[i] == '(') {
                // When encountering '(', push the current result and sign onto the stack
                operands.push(result);
                operands.push(sign);
                // Reset result and sign for the new sub-expression inside the parentheses
                result = 0;
                sign = 1;
            } else if (s[i] == ')') {
                // Ending a sub-expression, pop sign from stack and multiply it with the current result
                result *= operands.top();
                operands.pop();
                // Add the result of the sub-expression to the result up to the '('
                result += operands.top();
                operands.pop();
            }
            // Ignore whitespace and other non-math characters
        }
        return result; // Return the final result
    }
};