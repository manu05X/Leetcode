class Solution {
    func sortedSquares(_ nums: [Int]) -> [Int] {
        let n = nums.count

        var right = n-1
        var left = 0

        var result = nums
        var currIndx = right
        while currIndx >= 0 {
            if abs(nums[left]) < abs(nums[right]) {
                result[currIndx] = nums[right] * nums[right]
                right -= 1
            } else {
                result[currIndx] = nums[left] * nums[left]
                left += 1
            }
            currIndx-=1
        }
        return result
    }
}