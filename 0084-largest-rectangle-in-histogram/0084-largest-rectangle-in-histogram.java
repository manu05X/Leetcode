class Solution {
    public int largestRectangleArea(int[] heights) {
        int area;
		int maxArea = 0;
		int i = 0;
		Stack<Integer> s = new Stack<>();
		while(i < heights.length)
        {
			if(s.isEmpty() || heights[s.peek()] <= heights[i])
            {
				s.push(i);
				i++;
			}
			else
            {
				int temp = s.pop();
				// s.pop();
				if(s.isEmpty())
                {
					area = heights[temp] * i;
				}
				else
                {
					area = heights[temp] * (i - s.peek() - 1);
				}
				if(area > maxArea)
                {
					maxArea = area;
				}
			}
		}
		while(!s.isEmpty())
        {
			int temp = s.pop();
			// s.pop();
			if(s.isEmpty())
            {
				area = heights[temp] * i;
			}
			else
            {
				area = heights[temp] * (i - s.peek() - 1);
			}
			if(area > maxArea)
            {
				maxArea = area;
			}
		}
		return maxArea;
    }
}