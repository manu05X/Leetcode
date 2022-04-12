class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int read_idx = 0;
        int write_idx = 0;
        
        while(read_idx <= nums.size()-1){
            if(nums[read_idx] != 0){
                nums[write_idx] = nums[read_idx];
                write_idx++;
            }
            read_idx++;
        }
        
        while(write_idx <= nums.size()-1){
            nums[write_idx] = 0;
            write_idx++;
        }
    }
};