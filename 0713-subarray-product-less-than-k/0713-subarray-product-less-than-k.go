func numSubarrayProductLessThanK(nums []int, k int) int {
    n := len(nums)
    product := 1
    left := 0
    ans := 0;

    for right := 0; right < n; right++{
        product *= nums[right]

        for  left <= right && product >= k{
            product = product/nums[left]
            left++
        }

        ans += (right - left)+1
    }

    return ans;
}