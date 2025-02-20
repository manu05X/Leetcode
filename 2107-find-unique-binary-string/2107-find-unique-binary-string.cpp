class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for(int i = 0; i < nums.size(); i++){
            char curr = nums[i][i];
            if(curr == '0'){
                ans += '1';
            }
            else{
                ans += '0';
            }
        }

        return ans;
    }
};