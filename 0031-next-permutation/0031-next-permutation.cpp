class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int p,l;
        
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                p = i;
                break;
            }
        }
        
        if(p < 0){
            reverse(nums.begin(), nums.end());
        } else {
            for(l = n-1; l > p; l--){
                if(nums[l] > nums[p]){
                    break;
                }
            }
            swap(nums[p], nums[l]);
    	    reverse(nums.begin() + p + 1, nums.end());
        }
        
        
    }
};