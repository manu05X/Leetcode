class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int w = 1;

        for(int r = 1; r < n; r++){
            if(nums[r-1] != nums[r]){
                nums[w] = nums[r];
                w++;
            }
        }
        return w;
    }
};