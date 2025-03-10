class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i =1;i<=n;i++){
            ans = ans ^ i; // 0^1^2^3
        }
        for(int i =0;i<nums.size();i++){
            ans= ans^nums[i]; // (3^0^1)^(0^1^2^3)
        }
        /*
        = (3^0^1)^(0^1^2^3)
        = (0^0)^(1^1)^2^(3^3)
        = 0^0^2^0
        = 0^2^0
        = 0^2
        = 2
        */

        return ans;
    }
};


/*
class Solution {
public:
    int missingNumber(vector<int>& array) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = array.size();
        // Initialize 'missing' to the size of the vector, as the array is
        // supposed to contain all numbers from 0 to n, so 'n' is the initial candidate.
        int expectedSum = n*(n+1)/2;
        
        int actualSum = 0;
        for(int i = 0; i < n; i++){
            actualSum += array[i];
        }
        return expectedSum - actualSum;
    }
};
*/

/*
class Solution {
public:
    int missingNumber(vector<int>& array) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = array.size();
        // Initialize 'missing' to the size of the vector, as the array is
        // supposed to contain all numbers from 0 to n, so 'n' is the initial candidate.
        int missing = n;
        
        for(int i = 0; i < n; i++){
            // XOR 'missing' with the current index 'i' and the element at that index 'nums[i]'.
            // The idea behind this is that when a number and its index are XOR'ed
            // in the range from 0 to n, the only number that will not be cancelled
            // out is the missing number.
            missing ^=i^array[i];
        }
        return missing;
    }
};
*/