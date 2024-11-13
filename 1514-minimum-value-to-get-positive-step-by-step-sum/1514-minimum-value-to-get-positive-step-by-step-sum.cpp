class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = INT_MAX;
        int temp = 0;

        for(int i = 0; i < nums.size(); i++){
            temp += nums[i];
            minVal = min(temp, minVal);
        }


        return minVal <= 0 ? abs(minVal)+1 : 1;
    }
};
