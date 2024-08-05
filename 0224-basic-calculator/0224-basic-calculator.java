class Solution {
    public int calculate(String s) {
     // Stack to hold the intermediate results and signs
        Deque<Integer> stack = new ArrayDeque<>();
        // Initialize the sign as positive
        int sign = 1;
        // This will hold the final result of the evaluation
        int result = 0;
        // Length of the input string for iteration
        int length = s.length();

        // Iterating over each character in the string
        for (int i = 0; i < length; ++i) {
            char ch = s.charAt(i);
            // Check if the current char is a digit
            if (Character.isDigit(ch)) {
                int startIndex = i;
                int number = 0;
                // Build the number till we encounter a non-digit
                while (startIndex < length && Character.isDigit(s.charAt(startIndex))) {
                    number = number * 10 + s.charAt(startIndex) - '0';
                    startIndex++;
                }
                // Update the result with the current number and sign
                result += sign * number;
                // Move the pointer to the end of the number
                i = startIndex - 1;
            } else if (ch == '+') {
                // Set sign as positive for addition
                sign = 1;
            } else if (ch == '-') {
                // Set sign as negative for subtraction
                sign = -1;
            } else if (ch == '(') {
                // Push the result and sign on the stack before the parenthesis
                stack.push(result);
                stack.push(sign);
                // Reset result and sign for the expression inside the parenthesis
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                // After closing parenthesis, result is the evaluated value inside the parenthesis
                // Pop the sign before the parenthesis and multiply it with the current result,
                // then add the result before the parenthesis
                result = stack.pop() * result + stack.pop();
            }
        }
        // Return the final result of the evaluation
        return result;
    }
}