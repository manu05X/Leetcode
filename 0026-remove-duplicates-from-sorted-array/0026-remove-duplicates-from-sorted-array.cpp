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












// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int i = 0; 
//         int j = 1;

//         while(j < nums.size())
//         {
//             if(nums[i] != nums[j]){
//                 i++;
//                 nums[i] = nums[j];
//             }
//             j++;
//         }
//         return i+1;
//     }
// };