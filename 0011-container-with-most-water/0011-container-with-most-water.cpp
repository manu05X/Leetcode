class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; 
        int r = height.size()-1;
        int maxArea = 0;

        while(l < r)
        {
            int currArea = (min(height[r], height[l]) * (r-l));
            maxArea = max(currArea, maxArea);

            if(height[l] < height[r])
            {
                l++;
            }
            else{
                r--;
            }
        }
        return maxArea;
    }
};