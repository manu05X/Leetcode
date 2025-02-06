class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();

        for(int i = 0; i < n-2; i++){
            // to skip the 1st elements of nums and duplicate if nums[i-1]== nums[i]
            if(i == 0 || nums[i-1] != nums[i]){
                int lo = i+1;
                int hi = n-1;
                while(lo < hi){
                    int sum = nums[lo] + nums[hi] + nums[i];
                    if(sum < 0){
                        lo++;
                    }
                    else if(sum > 0){
                        hi--;
                    }
                    else
                    {
                        ans.add(Arrays.asList(nums[i], nums[lo++], nums[hi--]));
                        // to skip the duplicate element
                        while (lo < hi && nums[lo] == nums[lo - 1]) 
                            ++lo;
                    }
                }
            }
        }

        return ans;
    }
}

/*

Ì 0 || nums[i - 1] != nums[i]): This condition checks whether the current element (nums[i]) is the first occurrence of that particular value in the sorted arlOuterray or if it is different from the previous element.

Inner While Loop:

while (lo < hi && nums[lo] == nums[lo - 1]) ++lo;: This loop is used to skip over duplicate elements in the nums array.

It increments the lo pointer as long as the current element (nums[lo]) is the same as the previous one (nums[lo - 1]) and lo is less than hi.

This ensures that for a given triplet, only the first occurrence of each unique element is considered, avoiding duplicate triplets in the result.
 */