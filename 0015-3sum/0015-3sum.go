package main
import (
	"fmt"
	"sort"
)
func threeSum(nums []int) [][]int {
    n := len(nums);

    sort.Ints(nums);
    var res[][]int;

    for i := 0; i < n-2; i++{
        if i == 0 || nums[i] != nums[i-1]{
            lo := i+1
            hi := n-1

            for lo < hi{
                sum := nums[lo]+nums[hi]+nums[i]

                if sum < 0 {
                    lo++;
                } else if sum > 0{
                    hi--;
                } else {
                    res = append(res, []int{nums[i], nums[lo], nums[hi]})
                    lo++
                    hi--
                    // Skip duplicate elements to avoid duplicate triplets
					for lo < hi && nums[lo] == nums[lo-1] {
						lo++
					}
                }
            }
        }
    }

    return res;
}