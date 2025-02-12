class Solution {
public:
    int sumDigits(int numb) {
        int sum=0;
        while(numb) {
            sum+=numb%10;
            numb/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        vector<int> sameDigit(82, -1);
        int sum, maxSum=-1;
        for(int i=0; i<nums.size(); i++) {
            sum=sumDigits(nums[i]);
            if(sameDigit[sum]!=-1) {
                maxSum=max(maxSum, sameDigit[sum]+nums[i]);
                sameDigit[sum]=max(sameDigit[sum], nums[i]);
            } else {
                sameDigit[sum]=nums[i];
            }
        }
        return maxSum;
    }
};

/*
Why is the Maximum Sum of Digits 81?
The sum of digits of a number is obtained by adding its individual digits. The worst-case scenario occurs for the largest possible number.

Maximum Possible Number:

A 32-bit integer can have at most 10 digits (999999999 is the largest 10-digit number).
The largest digit sum occurs when all digits are 9.
Maximum Sum Calculation: 9+9+9+9+9+9+9+9+9+9=90
But in practical cases, we're working with positive integers (in constraints for such problems, negative values are usually not considered).
If we limit numbers to non-negative inputs, the maximum valid sum is 81 (999999999).

*/



/*
class Solution {
public:
    int sumOfDigits(int n) 
    {
        int sum = 0;
        while (n != 0) {

            // Extract the last digit
            int last = n % 10;

            // Add last digit to sum
            sum += last;

            // Remove the last digit
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        unordered_map<int, int> mp;

        for(const auto& x : nums){
            int sum = sumOfDigits(x);

            if(mp.find(sum) != mp.end()){
                ans = max(ans, mp[sum]+x);
            }

            // Store the maximum number seen so far for this digit sum
            mp[sum] = max(mp[sum], x);
        }

        return ans;

    }
};
*/