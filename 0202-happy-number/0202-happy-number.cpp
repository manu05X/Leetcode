class Solution {
public:
    int isHappyUntil(int number)
    {
        int totalSum = 0;
        while (number > 0)
        {
            int digit = number % 10;
            number = floor(number / 10);
            totalSum += digit * digit;
        }
        return totalSum;
    }
    bool isHappy(int n) {
        int sptr = n; // slow pointer
        int fptr = isHappyUntil(n); // fast pointer

        while(fptr != 1 && fptr != sptr)
        {
            sptr = isHappyUntil(sptr);
            fptr = isHappyUntil(isHappyUntil(fptr));
        } 
        
        if(fptr == 1)
        {
            return true;
        }
        else{
            return false;
        }
    }
};