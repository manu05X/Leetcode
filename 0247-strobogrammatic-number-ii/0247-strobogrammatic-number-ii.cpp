class Solution {
public:
    vector<string> findStrobogrammatic(int n){
        return helper(n,n);
    }

    // Helper function to recursively generate strobogrammatic numbers
    vector<string> helper(int n, int length) {
    // Base case: when n is 0, return an empty string
    if (n == 0) {
        return {""};
    }
    // Base case: when n is 1, return strobogrammatic digits for length 1
    if (n == 1) {
        return {"0", "1", "8"};
    }

    // Recursive case: generate strobogrammatic numbers for n-2
    vector<string> middles = helper(n - 2, length); // " "
    vector<string> result;

    // Iterate over the generated middles and create strobogrammatic numbers
    for (const string& middle : middles) {
        // If n is not equal to the original length, add "0" on both sides
        if (n != length) {
            result.push_back("0" + middle + "0");
        }
        // Add strobogrammatic numbers with "8" in the middle
        result.push_back("8" + middle + "8");
        // Add strobogrammatic numbers with "1" in the middle
        result.push_back("1" + middle + "1");
        // Add strobogrammatic numbers with "9" in the first half and "6" in the second half
        result.push_back("9" + middle + "6");
        // Add strobogrammatic numbers with "6" in the first half and "9" in the second half
        result.push_back("6" + middle + "9");
    }
    return result;
    }
};


/*
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

*/

/*

16708


*/