class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int res = 0, x1 = 0, x2 = 0;
        for(int n1 : nums1){
            x1^= n1;
        }

        for(int n2 : nums2){
            x2^=n2;
        }

        if(n%2 == 1){
            res^= x2;
        }

        if(m%2 == 1){
            res^=x1;
        }

        return res;
    }
};
/*

Let me explain this concept step by step using an example to make it clearer.
Let's say we have:
nums1 = [1, 2, 3] (length = 3, odd)
nums2 = [4, 5] (length = 2, even)
When we create every possible XOR pair between nums1 and nums2, each number in nums2 will appear 3 times (once with each number in nums1):
4 is used in:

1 ⊕ 4
2 ⊕ 4
3 ⊕ 4

5 is used in:

1 ⊕ 5
2 ⊕ 5
3 ⊕ 5

The key property of XOR is that:

When you XOR a number with itself an even number of times, it cancels out (equals 0)
When you XOR a number with itself an odd number of times, you get the number itself

In this case, because nums1's length is odd (3):

4 appears 3 times in the XOR operations
5 appears 3 times in the XOR operations

Therefore, both 4 and 5 will contribute to the final result (they won't cancel out) because they're each used an odd number of times. This is what "leaving a non-zero contribution" means - these numbers will affect the final result rather than canceling themselves out.
That's why in the code, when n (length of nums1) is odd, we XOR the result with x2 (the XOR of all numbers in nums2) - because each number in nums2 will effectively appear an odd number of times in the final result.
The same logic applies in reverse when nums2's length is odd - each number in nums1 will appear an odd number of times in the XOR operations and thus contribute to the final result.

*/