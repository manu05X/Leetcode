class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n,0);
        
        right[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--){
            right[i] = max(right[i+1], nums[i]);
        }
        // nums:[6,0,8,2,1,5]
        // n:6
        // right:[8,8,8,5,5,5]

        int p1 = 0, p2 = 0, maxWidth = 0;

        while(p2 < n){
            while(p1 < p2 && nums[p1] > right[p2]){
                p1++;
            }

            maxWidth = max(maxWidth, p2 - p1);
            p2++;
        }

        return maxWidth;
    }
};