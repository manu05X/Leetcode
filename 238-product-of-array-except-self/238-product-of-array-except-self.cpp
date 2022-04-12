/*
Algorithm
The algorithm for this solution is to first create a new array result with products of all elements to the left of each element. With temp initially set to 1, in each iteration, the code:

1> sets the value of temp to the current index of the result array.
2> updates temp by multiplying it with the current element in the original array. This causes temp to be the product of the elements that the loop have traversed so far.
This will store the product from the start of array to the i-1 index.

We can then multiply each element in the result array to the product of all the elements to the right of the array by traversing it in reverse. We set temp to 1 again and in each iteration we:

3> multiply the value of temp to the current index of the result array. It is important to multiply the value of temp here as this will ensure that all elements of the result array are products of elements to the right and the left of the original element.
4> update temp by multiplying it with the current element in the original array. This causes temp to be the product of the elements that the loop have traversed so far.
*/
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size(), temp = 1;
		vector<int> res(n);

    // Put in each index in res the product of all elements before it:
    for (int i=0; i<n; i++) {
        res[i] = temp;
        temp *= nums[i];
    }
    
    // Now multiply each one with all the elements after it:
    temp = 1;
    for (int i=n-1; i>=0; i--) {
        res[i] *= temp;
        temp *= nums[i];
    }
    
    return res;
}
};