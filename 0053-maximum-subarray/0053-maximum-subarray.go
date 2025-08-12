func maxSubArray(nums []int) int {
    n := len(nums)
    currSum := nums[0]
    ans := nums[0]

    for i := 1; i < n; i++ {
        currSum = max(currSum + nums[i], nums[i])
        ans = max(ans, currSum)
    }

    return ans;
}


func max(a, b int) int{
    if a > b{
        return a
    }
    return b
}