class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int wr = 0;
        int rd = 1;

        while(rd != n){
            if(nums[wr] != nums[rd]){
                wr++;
                nums[wr] = nums[rd];
                rd++;
            }
            else
                rd++;
        }

        return wr+1;
    }
};