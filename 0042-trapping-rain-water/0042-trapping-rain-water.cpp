class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int left_max = 0, right_max = 0;
        int ans = 0;
        
        while(left < right)
        {
            // by choosing this condition we are making sure that there is some element greater than a[low] to its right side
            if(height[left] <= height[right])
            {
                // if currElm is greater than left_max then update the leftmax
                if(height[left] >= left_max)
                    left_max = height[left];
                else
                    ans += left_max-height[left];
                
                left++;
            }
            else
            {
                //if currElm is greater than right_max update the rightmax
                if(height[right] >= right_max)
                    right_max = height[right];
                else
                    ans += right_max-height[right];
                
                right--;
            }
        }
        
        return ans;
    }
};