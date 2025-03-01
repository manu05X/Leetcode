class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        // Pointer to place non-zero elements
        int wrIdx = 0;

        for(int i = 0; i < n; i++){
            // Step 1: Merge adjacent equal elements if they are non-zero
            if(i < n-1 && nums[i] == nums[i+1]){
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
            
            // Step 2: Shift non-zero elements to the front
            if(nums[i] != 0){
                if(i != wrIdx){
                    swap(nums[i], nums[wrIdx]);
                }
                wrIdx++;
            }
        }
        
        return nums; 
    }
};