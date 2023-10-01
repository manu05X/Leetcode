class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int w = 0; 
        int r = 0;

        while(r < n){
            if(nums[r] == val){
                r++;
                continue;
            }
            nums[w] = nums[r];
            w++;
            r++;
        }

        return w;
    }
};