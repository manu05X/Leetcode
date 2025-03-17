class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(0);
        // cout.tie(0);
        
        // int n = nums.size();
        // int left = 0, total = 0;// Initialize start pointer to 0 and sum to 0
        // int windowSize = n+1;// Initializing windowSize to a max number

        // // Iterate over the input array
        // for(int right = 0; right < n; right++)
        // {
        //     total += nums[right]; // Increase the sum by the current element
        //     // check if we can remove elements from the start side of the subarray
        //     // while still satisfying the target condition
        //     while(total >= target)
        //     {
        //         // Finding size of current subarray
        //         int currWindow = (right+1) - left;
        //         // Update the answer with the new minimum length
        //         if(currWindow < windowSize){
        //             windowSize = currWindow;
        //         }
        //         // Subtract the first element of the subarray and move 'left' right
        //         total -= nums[left];
        //         left += 1;
        //     }
        // }

        // if(windowSize != n+1)
        //     return windowSize;
        // else
        //     return 0;
        int n = nums.size();
        int left = 0, right = 0, total = 0;
        int wnSize = n+1;

        for(int i = 0; i<n; i++) 
        {
           total+=nums[i];
           while(total >= target) 
           {
            int curWindow = (i+1)-left;
            if(curWindow < wnSize) 
                wnSize = curWindow;

            total-=nums[left];
            left++;
           }
        }
        
        if(wnSize != n+1)
            return wnSize;
        else 
            return 0;
    }
};