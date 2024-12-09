class Solution {
public:
    int findDivisionSum(vector<int>& nums, int divisor){
        int sum = 0;

        for(auto x : nums){
            sum += ceil((1.0*x)/divisor);
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxElm = INT_MIN;
        for(int i = 0; i < n; i++){
            maxElm = max(nums[i], maxElm);
        }

        int lo = 1;
        int hi = maxElm;
        int ans = 0;

        while(lo <= hi){
            // cout << "Low : "<<lo <<" High : "<<hi<<endl;
            int mid = (lo+hi)/2;

            int result = findDivisionSum(nums, mid);
            // cout<<"mid : "<<mid << " result : " << result <<endl;

            if(result <= threshold){
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }

            // cout<<"ans : " <<ans <<endl;
        }

        return ans;

    }
};