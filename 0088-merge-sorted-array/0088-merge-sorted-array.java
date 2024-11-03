class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int p1 = m-1;
        int p2 = n-1;

        int ptr = m+n-1;

        while(p1 >= 0 && p2 >= 0){
            if(nums1[p1] >= nums2[p2]){
                nums1[ptr] = nums1[p1];
                p1--;
            } else {
                nums1[ptr] = nums2[p2];
                p2--;
            }

            ptr--;
        }

        while(p1 >= 0){
            nums1[ptr] = nums1[p1];
            p1--;
            ptr--;
        }

        while(p2 >= 0){
            nums1[ptr] = nums2[p2];
            p2--;
            ptr--;
        }
    }
}

// [1,2,3,0,0,0]
// [2,5,6]

// [1,2,3,2,5,6] = n
// [1,2,2,3,5,6] = n + nlogn = 2nlogn


// [1,2,3,0,0,0]. p1 = m-1 = 2
//  p1

// [2,5,6] p2 = n-1 = 2
//p2


// ans_ptr = n+m-1 = 5

//  [1,2,2,3,5,6] ans;
//. a

// n+m