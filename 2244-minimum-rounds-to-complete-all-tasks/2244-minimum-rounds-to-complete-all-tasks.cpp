class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        
        for(int i = 0; i < tasks.size(); i++){
            mp[tasks[i]]++;
        }
        
        int ans = 0;
        for(auto i : mp){
            // cout << "First : " <<i.first <<" Second : "<<i.second <<"\n";
            int freq = i.second;
            
            if(freq == 1)
                return -1;
            if(freq % 3 == 0)
            {
                ans += freq/3;
                // cout <<freq <<" freq % 3 == 0 , "<< ans <<endl;
            }
            else
            {
                ans += freq/3 + 1;
                // cout << ans <<endl;
            }
        }
        
        return ans;
    }
};