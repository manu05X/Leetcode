class Solution {
public:
    vector<string> findStrobogrammatic(int n){
        return helper(n,n);
    }

    vector<string> helper(int n, int finalLength) {
        if(n == 0){
            return {""};
        }

        if(n == 1){
            return {"0","1", "8"};
        }

        // Recursively generate numbers of length (n-2)
        vector<string> smallerNumbers = helper(n - 2, finalLength);

        // Map to store valid strobogrammatic digit pairs
        unordered_map<char, char> rotatedDigits = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };

        vector<string> result;

        for(const string& num: smallerNumbers){
            for(const auto& p : rotatedDigits){
                if(n == finalLength && p.first == '0'){
                    continue;
                }

                result.push_back(p.first + num + p.second);
            }
        }

        return result;

    }
};

/*

16708


*/