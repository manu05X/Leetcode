class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> range;

        for(int i = 0; i < nums.size(); i++){
            string temp = "";
            int start = nums[i];
            int end = nums[i];
            while(i + 1 < nums.size() && nums[i+1] == nums[i]+1){
                i++;
            }
            if(start == nums[i]){
                temp += to_string(start);
            }
            else{
                temp += to_string(start);
                temp +="->";
                temp += to_string(nums[i]);
            }

            range.push_back(temp);
        }

        return range;
    }
};