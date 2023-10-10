class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        //Set the answer ans = n.
        int ans = n;
        //Remove duplicates from nums and then sort it.
        set<int> unique(nums.begin(), nums.end());
        vector<int> newNums;
        //We will call this new array newNums
        for(int num : unique){
            newNums.push_back(num);
        }

        //initialize the iterator over the indices of newNums
        int j = 0;
        for(int i = 0; i < newNums.size(); i++){
            //While newNums[j] is within our range (less than newNums[i] + n), increment j
            while(j < newNums.size() && newNums[j] < newNums[i]+n){
                j++;
            }

            //the number of elements already in our range
            int count = j-i;
            //Update ans with n - count if it is smaller.
            ans = min(ans, n-count);
        }

        return ans;
        
    }
};
//https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template!/