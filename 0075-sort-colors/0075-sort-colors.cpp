class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, mid = 0 ,hi = n-1;

        while(mid <= hi){
            switch(nums[mid]){
                case 0:
                    swap(nums[lo], nums[mid]);
                    lo++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                
                case 2:
                    swap(nums[mid], nums[hi]);
                    hi--;
                    break;
            }
        }
    }
};