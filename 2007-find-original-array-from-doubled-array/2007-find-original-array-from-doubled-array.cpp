class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2 != 0)
            return vector<int>{};
        vector<int> ans;
        sort(changed.begin(),changed.end());
        queue<int>q;
        
        for(int i = 0; i < changed.size(); i++)
        {
            if(!q.empty() && changed[i] == q.front()){
                q.pop();
            }
            else{
                q.push(changed[i]*2);
                ans.push_back(changed[i]);
            }
        }
        
        return !q.empty()?vector<int>{}: ans;
    }
};