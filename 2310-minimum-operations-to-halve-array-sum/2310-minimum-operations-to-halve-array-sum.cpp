class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();

        double sum = 0;
        priority_queue<double> pq;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            pq.push(nums[i]);
        }

        double targetSum = sum/2;
        int count = 0;
        while(targetSum > 0){
            count++;

            double currTop = pq.top();
            pq.pop();

            targetSum = targetSum - currTop/2;

            pq.push(currTop/2);
        }

        return count;


    }
};