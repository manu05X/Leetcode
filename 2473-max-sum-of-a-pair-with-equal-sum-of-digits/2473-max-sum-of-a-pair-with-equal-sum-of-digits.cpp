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