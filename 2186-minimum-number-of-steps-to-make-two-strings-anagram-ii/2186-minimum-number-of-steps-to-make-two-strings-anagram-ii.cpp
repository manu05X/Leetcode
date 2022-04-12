class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freqMap(26,0);
		
        for(auto ch: s)
			freqMap[ch-'a']++;
        for(auto ch: t)
			freqMap[ch-'a']--;
			
        int ans=0;
        for(int i=0;i<26;i++)
			ans+=abs(0-freqMap[i]);
			
        return ans;
    }
};