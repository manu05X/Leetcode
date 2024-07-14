class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        let n = nums.count

        if n == 0 {return 0}
        var wd = 0

        for rd in 1..<n {
            if nums[rd] != nums[wd] {
                wd += 1
                nums[wd] = nums[rd]
            }
        }

        return wd+1
    }
}