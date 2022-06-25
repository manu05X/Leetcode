class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) 
    {
        int n = security.size();
        vector<int> prefix(n,0), sufix(n,0);
        
        for(int i = 1; i < n; i++)
        {
            if(security[i] <= security[i-1])
            {
                prefix[i] = prefix[i-1]+1;
            }
        }
        
        for(int i = n-2; i >= 0; i--)
        {
            if(security[i] <= security[i+1])
            {
                sufix[i] = sufix[i+1]+1;
            }
        }
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++)
        {
            if(time <= prefix[i] and time <= sufix[i])
            {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};