class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();

        // Map to store valid strobogrammatic digit pairs
        unordered_map<char, char> rotatedDigits = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };

        string rotatedString = "";

        // Traverse the string backwards
        for(int i = n-1; i >= 0; i--){
            char c = num[i];
            
            // If the character is not strobogrammatic, return false
            if(rotatedDigits.find(c) == rotatedDigits.end()){
                return false;
            }

            // Append the corresponding rotated character
            rotatedString += rotatedDigits[c];
        }

        // Check if the reversed and rotated string matches the original
        return num == rotatedString;
    }
};