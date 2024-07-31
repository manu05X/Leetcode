class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for(int i = 0; i < n; i++){
            int idx = nums[i]-1;
            if(nums[i] > 0 && nums[i] <= n && nums[idx] != nums[i]){
                int temp = nums[idx];
                nums[idx] = nums[i];
                nums[i] = temp;

                i--;
            }
        }

        for(int i= 0; i < n; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }

        return n+1;
    }
}

/*

Let's take an example array to illustrate the solution approach: nums = [3, 4, -1, 1].

We start by iterating through the array. The length of the array n = 4.

The first element nums[0] is 3, which is a positive integer and within the range [1, n]. The correct position for 3 is at index 2 (3 - 1 = 2). Since nums[2] is -1, we swap nums[0] with nums[2]. Now the array looks like this: nums = [-1, 4, 3, 1].

Next, we look at the element in the current index 0 which is now -1. Since -1 is negative and not in the range [1, n], we move to the next index.

The first element nums[1] is 4, which is a positive integer and within the range [1, n]. The correct position for 4 is at index 3 (4 - 1 = 3). Since nums[3] is 1, we swap nums[1] with nums[3]. Now the array looks like this: nums = [-1, 1, 3, 4].

Next, we look at the element in the current index 1 which is now 1. element nums[1] is 1, which is a positive integer and within the range [1, n]. The correct position for 1 is at index 0 (1 - 1 = 0). Since nums[0] is -1, we swap nums[1] with nums[0]. Now the array looks like this: nums = [1, -1, 3, 4].

Next, we look at the element in the current index 1 which is now -1. Since -1 is negative and not in the range [1, n], we move to the next index.

At index 2, the element is 3 and is already in its correct position (index 2 + 1 = 3), so we move forward.

At index 3, we have the number 4, and is already in its correct position (index 3 + 1 = 4), so we move forward.
Now the array looks like this: nums = [1, -1, 3, 4].

At this point, we have iterated through the entire array, placing all positive integers within the range [1, n] in their correct positions.

We now perform a final scan through the array. At index 0, we have nums[0] = 1, which is the correct placement.

At index 1, we should have 2, but instead, we have nums[1] = -1. This tells us that 2 is the smallest missing positive integer because it is not at its correct position—which would be index 1.

We conclude that 2 is the smallest missing positive integer in the array nums.

The array after processing is nums = [1, -1, 3, 4]., and the smallest missing positive integer is 2.

*/