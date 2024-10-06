class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();

        // Iterate over all elements in the input vector
        for(int i = 0; i < n; i++){
            // Calculate the index from the value
            int idx = abs(nums[i])-1;
            // If the value at the calculated index is positive, negate it
            // Negation marks that the number at 'index + 1' exists in the array
            if(nums[idx] > 0){
                nums[idx] = -nums[idx];
            }
        }
        // Initialize an empty vector to store missing numbers
        vector<int> ans;
        // Iterate over the numbers from 1 to n and find which indices have positive values
        for(int i = 0; i < n; i++){
            // If the value at index 'i' is positive, it means 'i + 1' is missing
            if(nums[i] > 0){
                // Add the missing number to the result vector
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};


/*
Why Does This Work?
- Since you are marking the presence of numbers directly in the input array, there’s no need for additional space to store which numbers were seen.
- By negating the value at an index, you effectively mark that the number i + 1 exists in the array.
- By leaving unmarked (positive) values in the array, you can later identify which numbers are missing


nums = [4,3,2,7,8,2,3,1]
1. '4' is present in nums. Mark as present by negating nums[4-1] = nums[3].  Thus, nums[3] = -7
   => nums = [4,3,2,-7,8,2,3,1]
	
2. '3' is present in nums. Mark as present by negating nums[3-1] = nums[2].  Thus, nums[2] = -2
   => nums = [4,3,-2,-7,8,2,3,1]

3. '2' is present in nums. nums[2-1] = nums[1].Thus, nums[1] = -3
   => nums = [4,-3,-2,-7,8,2,3,1]
   
4. '7' is present in nums. nums[7-1] = nums[6].Thus, nums[6] = -3
   => nums = [4,-3,-2,-7,8,2,-3,1]

5. '8' is present in nums. nums[8-1] = nums[7] .Thus, nums[7] = -1
   => nums = [4,-3,-2,-7,8,2,-3,-1]
   
6. '2' is present in nums. .Thus, nums[1] = -3
   => nums = [4,-3,-2,-7,8,2,-3,-1]   
  
7. '3' is present in nums. nums[3-1] = nums[2] .Thus, nums[2] = -2
   => nums = [4,-3,-2,-7,8, 2,-3,-1]   

7. '1' is present in nums. nums[1-1] = nums[0].Thus, nums[0] = -4
   => nums = [-4,-3,-2,-7,8,2,-3,-1]   

Now, the only elements nums[i] which are positive are those where 'i+1' is not found in nums array
These are => nums[4] and nums[5].
That means 5 and 6 an not present in the initial nums array
*/