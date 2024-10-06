class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int fast = nums[0];
        int slow = nums[0];
        
        // run loop till slow != fast
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        // reassign fast to nums[0]
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};

/*
This array can be visualized as a linked list:
- Start at index 0 (value = 1) → go to index 1 (value = 3) → go to index 3 (value = 2) → go to index 2 (value = 4) → go to index 4 (value = 2), and back to index 2 again. The cycle is formed between indices 2 and 4.

- The slow pointer moves one step at a time, and the fast pointer moves two steps at a time. Eventually, they both enter the cycle and meet at some point inside the cycle.

- After the meeting, resetting the fast pointer to the start and moving both pointers one step at a time will ensure that they meet at the cycle's entry point, which corresponds to the duplicate number.



How the Algorithm Works:
Why is there a cycle?
-  Since each number in the array is between 1 and n, each number can be treated as a pointer to the next index. The duplicate number creates a situation where two different indices point to the same index, forming a cycle.

Why does the second phase work?
- After the slow and fast pointers meet inside the cycle, resetting fast to the start of the array and moving both pointers one step at a time ensures that they will meet at the entry point of the cycle, which is the duplicate number. This is because the distance from the start of the array to the start of the cycle is the same as the distance from where the pointers met to the start of the cycle.

*/