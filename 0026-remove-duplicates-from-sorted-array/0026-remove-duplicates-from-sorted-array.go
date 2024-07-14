func removeDuplicates(nums []int) int {
    ln := len(nums)
    if ln <= 1 {
        return ln
    }

    wr := 0
    for rd := 1; rd < ln; rd++ {
        if nums[wr] != nums[rd] {
            wr++
            nums[wr] = nums[rd]
        }
    }

    return wr+1
}