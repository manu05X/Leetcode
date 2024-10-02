class Solution {
    func sortColors(_ nums: inout [Int]) {
        let n = nums.count
        var lo = 0, hi = n - 1, mid = 0
        
        while mid <= hi {
            if nums[mid] == 0 {
                nums.swapAt(lo, mid)
                lo += 1
                mid += 1
            } else if nums[mid] == 1 {
                mid += 1
            } else { // nums[mid] == 2
                nums.swapAt(hi, mid)
                hi -= 1
            }
        }
    }
}