//revise
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minVal = INT_MAX, maxVal = INT_MIN, n = nums.size(), left = -1, right = -1;
        for(int i = 1;i<n;i++) {
            if(nums[i]<nums[i-1]) {
                minVal = min(minVal, nums[i]);
            }
        }

        for(int i = n-2;i>=0;i--) {
            if(nums[i+1]<nums[i]) {
                maxVal = max(maxVal, nums[i]);
            }
        }
        
        for(int i = 0;i<n;i++) {
            if(nums[i]>minVal) {
                left = i;
                break;
            }
        }

        for(int i = n-1;i>=0;i--) {
            if(nums[i]<maxVal) {
                right = i;
                break;
            }
        }

        return (left == -1) ? 0: (right - left +1);
    
    }
};


/*

i = 1 → nums[1]=6, nums[0]=2 → 6 < 2? No
i = 2 → nums[2]=4, nums[1]=6 → 4 < 6? Yes
      minVal = min(INT_MAX, 4) → minVal = 4
i = 3 → nums[3]=8, nums[2]=4 → 8 < 4? No
i = 4 → nums[4]=10, nums[3]=8 → No
i = 5 → nums[5]=9, nums[4]=10 → 9 < 10? Yes
      minVal = min(4, 9) → minVal = 4
i = 6 → nums[6]=15, nums[5]=9 → No

minVal = 4



i = 5 → nums[6]=15, nums[5]=9 → 15 < 9? No
i = 4 → nums[5]=9, nums[4]=10 → 9 < 10? Yes
      maxVal = max(INT_MIN, 10) → maxVal = 10
i = 3 → nums[4]=10, nums[3]=8 → 10 < 8? No
i = 2 → nums[3]=8, nums[2]=4 → 8 < 4? No
i = 1 → nums[2]=4, nums[1]=6 → 4 < 6? Yes
      maxVal = max(10, 6) → maxVal = 10
i = 0 → nums[1]=6, nums[0]=2 → 6 < 2? No

maxVal = 10


i = 0 → nums[0]=2 > 4? No
i = 1 → nums[1]=6 > 4? Yes
      left = 1
      break


i = 6 → nums[6]=15 < 10? No
i = 5 → nums[5]=9 < 10? Yes
      right = 5
      break


(left == -1)? 0 : (right - left + 1)
(1 == -1)? No → (5 - 1 + 1) = 5

Final Answer = 5


Meaning

The subarray nums[1..5] = [6,4,8,10,9] must be sorted to make the whole array sorted.

*/