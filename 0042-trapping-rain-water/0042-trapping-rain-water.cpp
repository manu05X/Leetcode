class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int left_max = 0, right_max = 0;
        int water = 0;

        while(left < right)
        {
            /* If height[left] is smaller than height[right] as water trapped would be dependant on smaller height of bar in current direction (from left to right). 
            As soon as we find the bar at other end (right) is smaller, we start iterating in opposite direction (from right to left).*/
            if(height[left] <= height[right]){
                //If height[left] is greater than left_max till current index from left, update left_max
                if(height[left] >= left_max){
                    left_max = height[left];
                }
                else{
                    // add water
                    water += left_max - height[left];
                }
                left++;
            }
            else{
                //If height[right] is greater than right_max till current index from right, update left_max
                if(height[right] >= right_max){
                    right_max = height[right];
                }
                else{
                    water += right_max - height[right];
                }
                right--;
            }
        }

        return water;
    }
};


/*
class Solution {
    public int trap(int[] height) {
        // time : O(n)
        // space : O(1)
        if (height.length==0) return 0; 
        int left = 0, right = height.length-1; 
        int leftMax=0, rightMax=0; 
        int ans = 0; 
        while (left < right) {
            if (height[left] > leftMax) leftMax = height[left]; 
            if (height[right] > rightMax) rightMax = height[right];
            if (leftMax < rightMax) {
                ans += Math.max(0, leftMax-height[left]); 
                left++; 
            } else {
                ans += Math.max(0, rightMax-height[right]); 
                right--; 
            }
        }
        return ans; 
    }
}
 */