class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        // // Precompute all palindromic substrings
        // for (int end = 0; end < n; ++end) {
        //     for (int start = 0; start <= end; ++start) {
        //         if (s[start] == s[end] && (end - start <= 2 || isPal[start + 1][end - 1])) {
        //             isPal[start][end] = true;
        //         }
        //     }
        // }

        // Precompute all palindromic substrings using start and end
        for (int end = 0; end < n; ++end) {
            for (int start = 0; start <= end; ++start) {
                if (s[start] == s[end]) {
                    if (end - start <= 2) {
                        isPal[start][end] = true;
                    } else {
                        isPal[start][end] = isPal[start + 1][end - 1];
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (isPal[0][i]) {
                dp[i] = 0; // No cut needed if whole substring is palindrome
            } else {
                dp[i] = i; // Worst case: cut at every position
                for (int j = 0; j < i; ++j) {
                    if (isPal[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};

/*
a  a  b    
--------
T  T  F   <- isPal[0][*] 
   T  F   <- isPal[1][*]
      T   <- isPal[2][*]



Index: 0  1  2
Cuts:  0  0  1



*/



/*
class Solution {
public:
    int minCut(string s) {
        int minimumCut = s.length() - 1;
        return findMinimumCut(s, 0, s.length() - 1, minimumCut);
    }
    // minimumCut => total number of char - 1 => aab = 3-1 = 2
    int findMinimumCut(string &s, int start, int end, int minimumCut) {
        // base condition, no cut needed for an empty substring or palindrome
        // substring.
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }
        for (int currentEndIndex = start; currentEndIndex <= end;currentEndIndex++) 
        {
            // find result for substring (start, currentEnd) if it is palindrome
            if (isPalindrome(s, start, currentEndIndex)) 
            {
                int currCount = findMinimumCut(s, currentEndIndex + 1,end, minimumCut);
                minimumCut = min(minimumCut, 1 + currCount);
            }
        }
        return minimumCut;
    }

    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};
*/