class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        while(k--){
            auto [currValue, idx] = pq.top();
            pq.pop();

            // Update the selected value by multiplying it with the multiplier
            nums[idx] = currValue * multiplier;

            pq.push({nums[idx], idx});
        }

        return nums;
    }
};