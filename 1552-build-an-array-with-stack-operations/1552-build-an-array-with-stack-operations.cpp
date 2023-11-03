class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 0;
        
        for (int num : target) 
        {
            while (i < num - 1) 
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
            
            ans.push_back("Push");
            i++;
        }
        
        return ans;
    }
};

/*
target: [3,6,7,9], n = 10

Output: ["Push","Pop","Push","Pop","Push","Push","Pop","Push","Pop","Push","Push","Push","Pop","Push"]
*/