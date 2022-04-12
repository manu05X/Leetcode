/*
Algorithm
We will keep two markers: read_index and write_index and point them to the start of the array

While moving read_index towards the end of the array:

1> If read_index points to 0, skip.
2> If read_index points to a non-zero value, write the value at               read_index to write_index and increment the write_index.
Assign zeros to all the values after the write_index and to the current position of write_index as well.
*/
class Solution {
    public void moveZeroes(int[] nums) {
        int read_idx = 0;
        int write_idx = 0;
        
        while(read_idx <= nums.length-1){
            if(nums[read_idx] != 0){
                nums[write_idx] = nums[read_idx];
                write_idx++;
            }
            read_idx++;
        }
        
        while(write_idx <= nums.length-1){
            nums[write_idx] = 0;
            write_idx++;
        }
    }
}