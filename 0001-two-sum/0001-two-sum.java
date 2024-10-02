//6.1.24
// class Solution {
//     public int[] twoSum(int[] nums, int target) {
//         int n = nums.length;
//         Map<Integer, Integer> mp=new HashMap<>();
//         int ans[] = new int[2];

//         for(int i=0; i<n;i++)
//         {
//           int difference=target-nums[i]; //9-2=7
//           if(mp.containsKey(difference) == true)
//           {
//               ans[0] = mp.get(difference); // 4->1; mp.get(4) = 1 // map wala index
//               ans[1] = i; // current index
//             return ans;
//           }
//           //      k     V
//           mp.put(nums[i],i);
//         }
//         return ans;
//     }
// }

//[3,4,9,6,4] , T = 8
//[1, 4]


class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        Map<Integer, Integer> mp=new HashMap<>();
        //int ans[] = new int[2];

        for(int i=0; i<n;i++)
        {
          int difference=target-nums[i]; //9-2=7
          if(mp.containsKey(difference) == true)
          {
            //   ans[0] = mp.get(difference); // 4->1; mp.get(4) = 1 // map wala index
            //   ans[1] = i; // current index
            return new int[]{mp.get(difference), i};
          }
          //      k     V
          mp.put(nums[i],i);
        }
        return new int[]{};
    }
}