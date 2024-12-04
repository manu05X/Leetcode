class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(n  > m){
            return findMedianSortedArrays(nums2, nums1);
        }

        int l = 0;
        int h = n;

        int leftHalf = (n+m+1)/2;

        int totalLeng = n+m;

        while(l <= h){
            int mid1 = (l+h)/2;
            int mid2 = leftHalf-mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 < n){
                r1 = nums1[mid1];
            }

            if(mid2 < m){
                r2 = nums2[mid2];
            }

            if(mid1-1 >= 0){
                l1 = nums1[mid1-1];
            }

            if(mid2-1 >= 0){
                l2 = nums2[mid2-1];
            }



            if(l1 <= r2 && l2 <= r1){
                if(totalLeng % 2 == 1){
                    return max(l1,l2);
                }

                return ((double)(max(l1,l2) + min(r1,r2))) / 2.0;
            }
            else if(l1 > r2){
                h = mid1 - 1;
            } else {
                l = mid1+1;
            }

        }

        return 0;
    }
};

/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); // Size of the first array
        int m = nums2.size(); // Size of the second array

        // Ensure nums1 is the smaller array for optimized binary search
        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int l = 0; // Start of the binary search range
        int h = n; // End of the binary search range
        int leftHalf = (n + m + 1) / 2; // Total elements on the left half of the merged array
        int totalLength = n + m; // Combined length of both arrays

        // Binary search to partition nums1 and nums2
        while (l <= h) {
            int mid1 = (l + h) / 2; // Partition index for nums1
            int mid2 = leftHalf - mid1; // Partition index for nums2 (complementary to mid1)

            // Boundary values for the partitions
            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN; // Left of partition in nums1
            int r1 = (mid1 < n) ? nums1[mid1] : INT_MAX;     // Right of partition in nums1
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN; // Left of partition in nums2
            int r2 = (mid2 < m) ? nums2[mid2] : INT_MAX;     // Right of partition in nums2

            // Check if the partitions are valid (l1 <= r2 and l2 <= r1)
            if (l1 <= r2 && l2 <= r1) {
                // If total length is odd, return the max of left side
                if (totalLength % 2 == 1) {
                    return max(l1, l2);
                }
                // If total length is even, return the average of the middle two elements
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
            // Adjust binary search range
            else if (l1 > r2) {
                h = mid1 - 1; // Move search range to the left
            } else {
                l = mid1 + 1; // Move search range to the right
            }
        }

        return 0; // This point should never be reached
    }
};

*/