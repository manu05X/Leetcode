class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        //Set the answer ans = n.
        int ans = n;
        //Remove duplicates from nums and then sort it.
        HashSet<Integer> unique = new HashSet<>();
        for(int num : nums){
            unique.add(num);
        }

        //We will call this new array newNums
        int[] newNums = new int[unique.size()];
        int index = 0;

        for(int num : unique){
            newNums[index++] = num;
        }

        Arrays.sort(newNums);
        //initialize the iterator over the indices of newNums
        int j = 0;
        for(int i = 0; i < newNums.length; i++)
        {
            //While newNums[j] is within our range (less than newNums[i] + n),increment j
            while(j < newNums.length && newNums[j] < newNums[i]+n){
                j++;
            }

            //the number of elements already in our range
            int count = j-i;
            //Update ans with n - count if it is smaller.
            ans = Math.min(ans, n-count);
        }

        return ans;
    }
}