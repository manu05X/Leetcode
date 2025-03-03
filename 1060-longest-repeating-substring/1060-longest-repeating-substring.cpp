class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int maxLen = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (s[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen;
    }
};


/*
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

*/