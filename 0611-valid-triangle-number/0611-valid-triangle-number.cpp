class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int count=0;

        for(int i = n-1; i >= 1; i--){
            int l = 0, r = i-1;

            while(l < r){
                if(nums[l] + nums[r] > nums[i]){
                    // If it is possible with a[l], a[r]
                    // and a[i] then it is also possible
                    // with a[l+1]..a[r-1], a[r] and a[i]
                    count += r-l;
                    // checking for more possible solutions
                    r--;
                } else {
                    // if not possible check for
                    // higher values of arr[l]
                    l++;
                }
            }
        }

        return count;

    }
};