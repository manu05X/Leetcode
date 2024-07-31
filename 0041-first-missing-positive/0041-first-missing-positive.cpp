class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int len = A.size();
        for(int i=0; i<len; i++) {
            // Start assigning the numbers from 1 to len with their respective positions.
            // We can ignore the numbers that doesn't lie in range of [1,len]
            // 3rd condition is used to prevent the case for infinite for loop
            // element at the index nums[i] - 1 should not be nums[i] itself).
            if(A[i] >0 && A[i] <= len &&  A[A[i]-1]!= A[i]) { 
                swap(A[A[i]-1], A[i]);
                i--;
            }
        }
        // Since in the above for loop we have assigned the numbers w.r.t positions
        for(int i=0; i<len; i++){
            // Once the number is not equal to its position, we can return that position
            if(A[i]!=i+1) return i+1; 
        }
        // If we were able to get every number in that range, then we can return len+1.
        return len+1;
    }
};
/*

Let's take an example array to illustrate the solution approach: nums = [3, 4, -1, 1].

We start by iterating through the array. The length of the array n = 4.

The first element nums[0] is 3, which is a positive integer and within the range [1, n]. The correct position for 3 is at index 2 (3 - 1 = 2). Since nums[2] is -1, we swap nums[0] with nums[2]. Now the array looks like this: nums = [-1, 4, 3, 1].

Next, we look at the element in the current index 0 which is now -1. Since -1 is negative and not in the range [1, n], we move to the next index.

At index 1, the element is 4, which is greater than n and does not need to be placed within the range [1, n]. So we move on.

At index 2, the element is 3 and is already in its correct position (index 2 + 1 = 3), so we move forward.

At index 3, we have the number 1, which should be at index 0 (1 - 1 = 0). We swap nums[3] with nums[0]. The array now becomes: nums = [1, 4, 3, -1].

At this point, we have iterated through the entire array, placing all positive integers within the range [1, n] in their correct positions.

We now perform a final scan through the array. At index 0, we have nums[0] = 1, which is the correct placement.

At index 1, we should have 2, but instead, we have nums[1] = 4. This tells us that 2 is the smallest missing positive integer because it is not at its correct position—which would be index 1.

We conclude that 2 is the smallest missing positive integer in the array nums.

The array after processing is nums = [1, 4, 3, -1], and the smallest missing positive integer is 2.

*/