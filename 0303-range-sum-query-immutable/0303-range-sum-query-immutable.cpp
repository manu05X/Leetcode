class NumArray {
public:
    vector<int>arr;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        arr.push_back(0);

        for(int i = 0; i < n; i++){
            arr.push_back(arr[i]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {

        return arr[right+1] - arr[left];
    }
};


// class NumArray {
// public:
//     vector<int> arr;
//     NumArray(vector<int>& nums) {
//         arr = nums;
//     }
    
//     int sumRange(int left, int right) {
//         int sum = 0;
//         for(int i = left; i <= right; i++){
//             sum += arr[i];
//         }

//         return sum;
//     }
// };

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */