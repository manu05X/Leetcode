class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        // Initialize the priority queue with elements and their indices
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        while(k--){
            // Get the smallest element and its index
            auto [currValue, idx] = pq.top();
            pq.pop();

            // Update the selected value by multiplying it with the multiplier
            nums[idx] = currValue * multiplier;

            // Push the updated value back into the priority queue
            pq.push({nums[idx], idx});
        }

        return nums;
    }
};