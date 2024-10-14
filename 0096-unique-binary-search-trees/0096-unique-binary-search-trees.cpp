class Solution {
public:
//Reducing memoization approch
    int numTrees(int n) {
         vector<int> dp(n+1, 0);

         dp[0] = 1;
         dp[1] = 1;

         for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
         }

         return dp[n];
    }
};


/*
class Solution {
public:
//Reducing memoization approch
    int numTrees(int n) {
         if (n == 0 || n == 1) {
            return 1;
        }
        unordered_map<int, int> map;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (map.find(i - 1) == map.end()) {
                map[i - 1] = numTrees(i - 1);
            }
            if (map.find(n - i) == map.end()) {
                map[n - i] = numTrees(n - i);
            }
            sum += map[i - 1] * map[n - i];
        }
        return sum;
    }
};

*/