func sortColors(nums []int)  {
    n := len(nums)

    lo, hi, mid := 0, n-1, 0

    for mid <= hi {
        switch nums[mid]{
            case 0: 
                nums[lo], nums[mid] = nums[mid], nums[lo]
                lo++
                mid++
            case 1:
                mid++
            case 2:
                nums[hi], nums[mid] = nums[mid], nums[hi]
                hi--
        }
    }
}