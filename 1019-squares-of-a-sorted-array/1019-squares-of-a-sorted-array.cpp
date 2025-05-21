class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        vector<int> ans(n,0);
        for(int i = n-1; i >= 0; i--){
            int leftSqr = nums[left]*nums[left];
            int rightSqr = nums[right]*nums[right];
            
            if(leftSqr > rightSqr){
                ans[i] = leftSqr;
                left++;
            } else {
                ans[i] = rightSqr;
                right--;
            }
            
        }
        
        return ans;
        
    }
};