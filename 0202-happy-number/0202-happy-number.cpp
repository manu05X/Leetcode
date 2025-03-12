class Solution {
public:
    // Helper function to compute the sum of squares of digits of a number
    int isHappyUntil(int number)
    {
        int totalSum = 0;
        while (number > 0)
        {
            int digit = number % 10; // Extract the last digit
            number = floor(number / 10); // Remove the last digit
            totalSum += digit * digit; // Add the square of the digit to the total sum
        }
        return totalSum; // Return the computed sum of squares of digits
    }

    // Function to determine if a number is a happy number
    bool isHappy(int n) {
        int sptr = n; // Slow pointer moves one step at a time
        int fptr = isHappyUntil(n); // Fast pointer moves two steps at a time

        // Detect a cycle using Floyd’s Cycle Detection algorithm
        while(fptr != 1 && fptr != sptr) // If fast pointer reaches 1, it's a happy number
        {
            sptr = isHappyUntil(sptr); // Move slow pointer one step
            fptr = isHappyUntil(isHappyUntil(fptr)); // Move fast pointer two steps
        } 
        
        // If fast pointer reaches 1, then n is a happy number
        if(fptr == 1)
        {
            return true;
        }
        else{
            return false; // Otherwise, a cycle was detected, so n is not a happy number
        }
    }
};
