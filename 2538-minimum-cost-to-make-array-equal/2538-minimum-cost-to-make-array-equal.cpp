class Solution {
public:
    long long computeCost(vector<int>& nums, vector<int>& cost, int target) {
        long long totalCost = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalCost += (long long)abs(nums[i] - target) * cost[i];
        }
        return totalCost;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        long long minCost = computeCost(nums, cost, nums[0]);

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long costMid = computeCost(nums, cost, mid);
            long long costMidNext = computeCost(nums, cost, mid + 1);

            minCost = min(costMid, costMidNext);

            // Move in the direction of lower cost
            if (costMid > costMidNext) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return minCost;
    }
};



/*
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        
        // Step 1: Pair and sort based on nums
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], cost[i]});
        }
        sort(arr.begin(), arr.end()); // Sorting based on nums

        // Step 2: Find the weighted median
        long long totalCost = 0;
        for (auto &[num, c] : arr) totalCost += c;

        long long prefixCost = 0, median = 0;
        for (auto &[num, c] : arr) {
            prefixCost += c;
            if (prefixCost >= (totalCost + 1) / 2) { // Weighted median condition
                median = num;
                break;
            }
        }

        // Step 3: Calculate minimum cost to make all elements equal to median
        long long minCost = 0;
        for (auto &[num, c] : arr) {
            minCost += abs(num - median) * c;
        }

        return minCost;
    }
};
*/