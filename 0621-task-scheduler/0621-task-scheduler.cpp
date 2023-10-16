class Solution {
    // Dezerve interview
public:
    int leastInterval(vector<char>& tasks, int n) {
        int x = tasks.size();
        unordered_map<char, int> mp;
        int count = 0;
        
        for(int i = 0; i < x; i++){
            mp[tasks[i]]++;
            count = max(count, mp[tasks[i]]);
        }
        int result = (count-1) * (n+1);
        //cout <<"From solve - " <<result <<endl;
        for(int i = 0; i < mp.size(); i++){
            if(mp[i] == count){
                result++;
            }
        }
        //cout <<"From - " <<result <<endl;
        
        return max(result,x);
    

    }
};
