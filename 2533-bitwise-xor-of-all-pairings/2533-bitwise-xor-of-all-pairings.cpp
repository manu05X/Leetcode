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

[2,1,3]
[10,2,5,0]




*/