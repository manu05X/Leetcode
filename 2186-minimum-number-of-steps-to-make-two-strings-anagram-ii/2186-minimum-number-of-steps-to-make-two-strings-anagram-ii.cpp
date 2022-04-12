class Solution {
public:
    int minSteps(string s, string t) {
    int ans = 0;
    vector<int> sCount(26, 0), tCount(26, 0);
	
    for(char ch: s){
		sCount[ch - 'a']++;
	}
    for(char ch: t) {
		tCount[ch - 'a']++;
	}
    for (int i = 0; i < 26; i++) 
		ans += abs(sCount[i] - tCount[i]);
		
    return ans;
}
};