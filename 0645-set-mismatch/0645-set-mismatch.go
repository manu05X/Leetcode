func findErrorNums(nums []int) []int {
    n := len(nums)
    dup, miss := -1, 1

    for i := 0; i < n; i++ {
        //idx := math.Abs(float64(nums[i]))-1;
        idx := int(math.Abs(float64(nums[i]))) - 1

        if nums[idx] < 0 {
            dup = idx+1
        } else {
            nums[idx] = -nums[idx];
        }
    }

    for i := 1; i < n; i ++ {
        if nums[i] > 0 {
            miss = i+1
        }
    }

    // Return the result as a slice
	return []int{dup, miss}
}