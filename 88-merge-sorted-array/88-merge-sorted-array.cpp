class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t1 = m-1, t2 = n-1, k = m+n-1;
        while(t1 >= 0 && t2 >= 0)
        {
            if(nums1[t1] > nums2[t2])
            {
                nums1[k] = nums1[t1];
                k--;
                t1--;
            }
            else
            {
                nums1[k] = nums2[t2];
                k--;
                t2--;
            }
        }
        while(t1 >= 0)
        {
            nums1[k--] = nums1[t1--];
        }
        while(t2 >= 0)
        {
            nums1[k--] = nums2[t2--];
        }
    }
};