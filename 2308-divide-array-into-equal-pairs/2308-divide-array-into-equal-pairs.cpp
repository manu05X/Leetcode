class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int s = nums.size();
        int n = s/2;
        vector<int> hm(501, 0);

        for(int i = 0; i < s; i++){
            hm[nums[i]]++;
        }

        for(int i = 0; i < s; i++){
            if(hm[nums[i]] % 2 != 0){
                return false;
            }
        }

        return true;

    }
};