class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int wd = 0;
        int rd = 1;

        while(rd < n){
            if(nums[rd] != nums[wd]){
                wd++;
                nums[wd] = nums[rd];
            }
            rd++;
        }

        return wd+1;
    }
};