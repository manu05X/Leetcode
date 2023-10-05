class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        // initializing 
        int num1, num2, count1 = 0, count2 = 0;

        for(int i = 0; i < n; i++)
        {
            // if candidate1 is same as array[i]
            if(num1 == nums[i])
            {
                count1++;
            }
            // if candidate2 is same as array[i]
            else if(num2 == nums[i])
            {
                count2++;
            }
            // if count1 and count2 become 0 then change num1 and num2
            else if(count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            // if the nums[i] diffrent then the num1 and num2
            else{
                count1--;
                count2--;
            }
        }

        // reinitializing count1 and count2 to 0
        count1 = count2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(num1 == nums[i])
            {
                count1++;
            }
            else if(num2 == nums[i])
            {
                count2++;
            }
        }

        // checking the count1 and count2 condition greater then n/3
        if(count1 > n/3)
        {
            ans.push_back(num1);
        }
        if(count2 > n/3)
        {
            ans.push_back(num2);
        }

        return ans;
    }
};