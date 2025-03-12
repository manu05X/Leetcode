class Solution {
private:
    // Return the first index where the value is equal to or greater than zero.
    int lowerBound(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        int index = nums.size();

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] < 0) {
                start = mid + 1;
            } else if (nums[mid] >= 0) {
                end = mid - 1;
                index = mid;
            }
        }

        return index;
    }

    // Return the first index where the value is greater than zero.
    int upperBound(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        int index = nums.size();

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] <= 0) {
                start = mid + 1;
            } else if (nums[mid] > 0) {
                end = mid - 1;
                index = mid;
            }
        }

        return index;
    }

public:
    int maximumCount(vector<int> &nums) {
        // All integers from the first non-zero to last will be positive
        // integers.
        int positiveCount = nums.size() - upperBound(nums);
        // All integers from the index 0 to index before the first zero index
        // will be negative.
        int negativeCount = lowerBound(nums);

        return max(positiveCount, negativeCount);
    }
};

/*

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int countN = 0;
        int countP = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                countP++;
            } else if(nums[i] < 0){
                countN++;
            } else {
                continue;
            }
        }

        return max(countP, countN);
    }
};

*/