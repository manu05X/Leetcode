class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        int left = 1, right = n - 1, ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hasRepeatingSubstring(s, mid)) {
                ans = mid; // Update answer, try for longer substrings
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

private:
    bool hasRepeatingSubstring(string& s, int len) {
        unordered_set<string> seen;
        for (int i = 0; i + len <= s.size(); i++) {
            string sub = s.substr(i, len);
            if (seen.count(sub)) return true;
            seen.insert(sub);
        }
        return false;
    }
};
