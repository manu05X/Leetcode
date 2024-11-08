func maxArea(height []int) int {
    n := len(height)

    lo,hi := 0,n-1
    maxArea := 0

    for lo < hi {
        h := min(height[lo], height[hi]);
        width := hi-lo;
        maxArea = max(maxArea, h*width) 

        if height[lo] < height[hi] {
            lo++
        } else {
            hi--
        }
    }

    return maxArea;
}


func min(a,b int) int{
    if a < b{
        return a;
    }
    return b;
}

func max(a,b int) int{
    if a > b{
        return a;
    }
    return b;
}