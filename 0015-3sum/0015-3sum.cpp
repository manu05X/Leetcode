class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        for(int i =0; i < n-2;i++)
        {
        // to skip the 1st elements of nums and duplicate if nums[i-1]== nums[i]
            if (i == 0  || nums[i-1] != nums[i]) 
            {
                int lo = i+1;
                int hi = n-1;

                while(lo < hi)
                {
                    int sum = nums[lo] + nums[hi] + nums[i];
                    if( sum < 0)
                    {
                        lo++;
                    }
                    else if(sum > 0)
                    {
                        hi--;
                    }
                    else
                    {
                        res.push_back({ nums[i], nums[lo++], nums[hi--] });
                        while(lo < hi && nums[lo] == nums[lo - 1]) // to skip the duplicate element
                            ++lo;
                    }
                }
            }
        }
        return res;
    }
};
/*
- TC : In the solution above, sorting the array takes O(nlog(n)) and the nested loop takes O(n^2) to find the triplet. Here, nis the number of elements in the input array. Therefore, the total time complexity of this solution is O(nlog(n)+n^2), which simplifies to O(n^2).
- Space Complexity of the provided solution is said to be O(log(n)) because of the use of the Arrays.sort() function, which typically implements an in-place sorting algorithm like Timsort or Quicksort.


Outer Conditional (if statement):

if (i == 0 || nums[i - 1] != nums[i]): This condition checks whether the current element (nums[i]) is the first occurrence of that particular value in the sorted array or if it is different from the previous element.

Inner While Loop:

while (lo < hi && nums[lo] == nums[lo - 1]) ++lo;: This loop is used to skip over duplicate elements in the nums array.

It increments the lo pointer as long as the current element (nums[lo]) is the same as the previous one (nums[lo - 1]) and lo is less than hi.

This ensures that for a given triplet, only the first occurrence of each unique element is considered, avoiding duplicate triplets in the result.
 */
