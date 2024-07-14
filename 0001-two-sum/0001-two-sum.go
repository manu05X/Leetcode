func twoSum(nums []int, target int) []int {
    mp := make(map[int]int)

    for idx,num := range nums {
        diff := target-num

        if index, found := mp[diff]; found {
            return []int{index, idx}
        }
        mp[num] = idx
    }

    return []int{}
}